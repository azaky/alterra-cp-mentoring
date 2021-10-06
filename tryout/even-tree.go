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

func main() {
	tokens := getints()
	n := tokens[0]

	adj := make([][]int, n)
	for i := 0; i < n-1; i++ {
		tokens = getints()
		x := tokens[0] - 1
		y := tokens[1] - 1
		adj[x] = append(adj[x], y)
		adj[y] = append(adj[y], x)
	}

	ans := 0

	var dfs func(int, int) int
	dfs = func(v, p int) int {
		size := 1
		for _, c := range adj[v] {
			if c == p {
				continue
			}
			size += dfs(c, v)
		}
		if size%2 == 0 {
			ans++
		}
		return size
	}
	dfs(0, -1)

	fmt.Println(ans - 1)
}
