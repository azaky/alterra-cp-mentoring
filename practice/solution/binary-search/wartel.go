package main

import (
	"bufio"
	"io"
	"os"
	"strconv"
	"strings"
)

var out = bufio.NewWriter(os.Stdout)
var in = bufio.NewReader(os.Stdin)

type Directory struct {
	Name, PhoneNumber string
}

func FindPhoneNumber(directories []Directory, name string) string {
	L, R := 0, len(directories)-1
	for L < R {
		M := (L + R) / 2
		if name == directories[M].Name {
			return directories[M].PhoneNumber
		} else if name < directories[M].Name {
			R = M - 1
		} else {
			L = M + 1
		}
	}
	if L == R && name == directories[L].Name {
		return directories[L].PhoneNumber
	}
	return "NIHIL"
}

func main() {
	tokens := getints()
	N, Q := tokens[0], tokens[1]
	dirs := make([]Directory, N)
	for i := 0; i < N; i++ {
		tokens := strings.Split(getline(), " ")
		dirs[i] = Directory{tokens[0], tokens[1]}
	}
	for i := 0; i < Q; i++ {
		name := getline()
		out.WriteString(FindPhoneNumber(dirs, name))
		out.WriteRune('\n')
	}
	if err := out.Flush(); err != nil {
		panic(err)
	}
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
