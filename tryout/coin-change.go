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

	dp := make([]int, n+1)
	dp[0] = 1

	tokens = getints()
	for _, c := range tokens {
		for j := c; j <= n; j++ {
			dp[j] += dp[j-c]
		}
	}

	fmt.Println(dp[n])
}
