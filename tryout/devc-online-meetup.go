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

func main() {
	_ = getints()
	var viewers int = 0
	var maxViewers int = 0

	d := getints()
	for _, di := range d {
		viewers += di
		if viewers > maxViewers {
			maxViewers = viewers
		}
	}
	fmt.Println(maxViewers)
}
