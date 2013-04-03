package main 

import (
	"fmt"
)

const V int = 500
const N int = 10010
const INF int = 1e8
var dp[N] int
var w, v [V]int

func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

func main() {
	var t int
	fmt.Scan(&t)
	for cas := 1;cas <= t;cas++ {
		var pig, all, n int
		fmt.Scan(&pig, &all, &n)
		all -= pig
		for i := 0;i < n;i++ {
			fmt.Scan(&v[i], &w[i])
		}
		for i := 1;i <= all;i++ {
			dp[i] = INF
		}
		for i := 0;i < n;i++ {
			for j := w[i];j <= all;j++ {
				dp[j] = min(dp[j], dp[j - w[i]] + v[i])
			}
		}
		if dp[all] != INF {
			fmt.Printf("The minimum amount of money in the piggy-bank is %d.\n", dp[all]);
		} else {
			fmt.Println("This is impossible.")
		}
	}
}

