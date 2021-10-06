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

	trie := make([][]int, 1)
	mark := make([]bool, 1)
	trie[0] = make([]int, 10)
	for i := 0; i < 10; i++ {
		trie[0][i] = -1
	}

	for i := 0; i < n; i++ {
		word := getline()
		node := 0
		leaf := false
		for _, c := range word {
			x := int(c - 'a')
			if trie[node][x] == -1 {
				nnode := len(trie)
				trie[node][x] = nnode
				trie = append(trie, make([]int, 10))
				mark = append(mark, false)
				for j := 0; j < 10; j++ {
					trie[nnode][j] = -1
				}
				leaf = true
			} else {
				leaf = false
			}
			node = trie[node][x]
			if mark[node] {
				fmt.Println("BAD SET")
				fmt.Println(word)
				return
			}
		}
		if !leaf {
			fmt.Println("BAD SET")
			fmt.Println(word)
			return
		}
		mark[node] = true
	}

	fmt.Println("GOOD SET")
}
