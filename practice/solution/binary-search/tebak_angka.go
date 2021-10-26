package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

var out = bufio.NewWriter(os.Stdout)
var in = bufio.NewReader(os.Stdin)

// Guess makes a guess and return "selamat", "terlalu kecil", or "terlalu besar"
func Guess(x int) string {
	if _, err := out.WriteString(fmt.Sprintf("%d\n", x)); err != nil {
		panic(err)
	}
	if err := out.Flush(); err != nil {
		panic(err)
	}

	return getline()
}

func Solve(A, B int) {
	for A <= B {
		m := (A + B) / 2
		res := Guess(m)
		if res == "selamat" {
			return
		} else if res == "terlalu kecil" {
			A = m
		} else if res == "terlalu besar" {
			B = m
		} else {
			panic(fmt.Errorf("unknown response: %s", res))
		}
	}
}

func main() {
	tokens := getints()
	Solve(tokens[0], tokens[1])
}

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
