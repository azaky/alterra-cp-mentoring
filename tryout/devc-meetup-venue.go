package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var in = bufio.NewReader(os.Stdin)

func getline() string {
	line, err := in.ReadString('\n')
	if err != nil {
		panic(err)
	}
	return line[:len(line)-1]
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

type Cell struct {
	R int
	C int
}

var dr = []int{0, 0, 1, -1}
var dc = []int{1, -1, 0, 0}
var dir = "RLDU"

func main() {
	tokens := getints()
	n := tokens[0]
	tokens = getints()
	ar := tokens[0] - 1
	ac := tokens[1] - 1
	mr := tokens[2] - 1
	mc := tokens[3] - 1

	grid := make([]string, n)
	for i := 0; i < n; i++ {
		grid[i] = getline()
	}

	queue := make([]Cell, 0)
	visited := make([][]bool, n)
	previous := make([][]int, n)
	for i := range visited {
		visited[i] = make([]bool, n)
		previous[i] = make([]int, n)
	}

	queue = append(queue, Cell{ar, ac})
	visited[ar][ac] = true

	for len(queue) > 0 {
		r := queue[0].R
		c := queue[0].C
		queue = queue[1:]
		if r == mr && c == mc {
			break
		}
		for d := 0; d < 4; d++ {
			nr := r + dr[d]
			nc := c + dc[d]
			if nr < 0 || nr >= n || nc < 0 || nc >= n || grid[nr][nc] != '.' || visited[nr][nc] {
				continue
			}
			queue = append(queue, Cell{nr, nc})
			visited[nr][nc] = true
			previous[nr][nc] = d
		}
	}

	if !visited[mr][mc] {
		fmt.Println("tersesat")
		return
	}

	ans := ""
	r, c := mr, mc
	for r != ar || c != ac {
		d := previous[r][c]
		ans = dir[d:d+1] + ans
		r -= dr[d]
		c -= dc[d]
	}
	fmt.Println(ans)
}
