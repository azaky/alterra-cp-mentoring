package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var in = bufio.NewReader(os.Stdin)

func getline() string {
	line, _, err := in.ReadLine()
	if err == io.EOF {
		return ""
	}
	if err != nil {
		panic(err)
	}
	return strings.TrimRight(string(line), "\r\n")
}

func getints() []int {
	tokens := strings.Split(getline(), " ")
	ints := make([]int, len(tokens))
	for i, token := range tokens {
		var err error
		ints[i], err = strconv.Atoi(token)
		if err != nil {
			panic(err)
		}
	}
	return ints
}

type LCA struct {
	n             int
	log           int
	parent, depth []int
	parentLift    [][]int
}

func NewLCA(parent, depth []int) *LCA {
	n := len(parent)
	log := 0
	for (1 << log) < n {
		log++
	}
	parentLift := make([][]int, n)
	for i := 0; i < n; i++ {
		parentLift[i] = make([]int, log+1)
		for j := range parentLift[i] {
			parentLift[i][j] = -1
		}
		parentLift[i][0] = parent[i]
	}
	for j := 1; j < log; j++ {
		for i := 0; i < n; i++ {
			if parentLift[i][j-1] != -1 {
				parentLift[i][j] = parentLift[parentLift[i][j-1]][j-1]
			}
		}
	}

	return &LCA{
		n:          n,
		log:        log,
		parent:     parent,
		depth:      depth,
		parentLift: parentLift,
	}
}

func (l *LCA) Find(u, v int) int {
	if l.depth[u] < l.depth[v] {
		u, v = v, u
	}
	for j := l.log; j >= 0; j-- {
		if l.depth[u]-(1<<j) >= l.depth[v] {
			u = l.parentLift[u][j]
		}
	}
	if u == v {
		return u
	}
	for j := l.log; j >= 0; j-- {
		if l.parentLift[u][j] != l.parentLift[v][j] {
			u, v = l.parentLift[u][j], l.parentLift[v][j]
		}
	}
	return l.parent[u]
}

type BIT struct {
	n      int
	values []int
}

func (b *BIT) Update(k, v int) {
	for x := k; x <= b.n; x += (x & -x) {
		b.values[x] += v
	}
}

func (b *BIT) Sum(k int) int {
	sum := 0
	for x := k; x > 0; x -= (x & -x) {
		sum += b.values[x]
	}
	return sum
}

func NewBIT(n int) *BIT {
	return &BIT{
		n:      n,
		values: make([]int, n+1),
	}
}

func main() {
	tokens := getints()
	n := tokens[0]
	q := tokens[1]

	adj := make([][]int, n)
	for i := 0; i < n-1; i++ {
		tokens = getints()
		x := tokens[0]
		y := tokens[1]
		adj[x] = append(adj[x], y)
		adj[y] = append(adj[y], x)
	}

	// DFS for Preorder & LCA
	preL := make([]int, n)
	preR := make([]int, n)
	parent := make([]int, n)
	depth := make([]int, n)

	var dfs func(int, int)
	counter := 0
	dfs = func(v, p int) {
		counter++
		preL[v] = counter
		parent[v] = p
		for _, c := range adj[v] {
			if c == p {
				continue
			}
			depth[c] = depth[v] + 1
			dfs(c, v)
		}
		preR[v] = counter
	}
	depth[0] = 0
	dfs(0, -1)

	lca := NewLCA(parent, depth)
	bit := NewBIT(n + 1)

	value := make([]int, n)
	for iq := 0; iq < q; iq++ {
		tokens = getints()
		t := tokens[0]
		x := tokens[1]
		y := tokens[2]
		if t == 1 {
			diff := y - value[x]
			bit.Update(preL[x], diff)
			bit.Update(preR[x]+1, -diff)
			value[x] += diff
		} else {
			p := lca.Find(x, y)
			ans := bit.Sum(preL[x]) + bit.Sum(preL[y]) - 2*bit.Sum(preL[p]) + value[p]
			fmt.Println(ans)
		}
	}
}
