package main
import "fmt"
const N int = 35000
var p[N] int
var pcnt int
var tags[N] bool

func getPrime() {
	pcnt = 0
	for i := 0;i < N;i++ {
		tags[i] = true
	}
	for i := 2;i < N;i++ {
		if tags[i] {
			p[pcnt] = i;
			pcnt++
		}
		for j := 0;j < pcnt && p[j] * i < N;j++ {
			tags[i * p[j]] = false
			if i % p[j] == 0 {
				break;
			}
		}
	}
}
const M int = 100001
var isPrime[M] bool
func max(a int, b int) int {
	if(a > b) {
		return a
	}
	return b
}
func main() {
	getPrime()
	var l, r, t int
	fmt.Scan(&t)
	for i := 0;i < t;i++ {
		if i != 0 {
			fmt.Println("")
		}
		fmt.Scan(&l, &r)
		bound := r - l + 1
		for j := 0;j < bound;j++ {
			isPrime[j] = true;
		}
		for j := 0;j < pcnt;j++ {
			k := max((l + p[j] - 1) / p[j], p[j])
			for ;k * p[j] <= r;k++ {
				isPrime[k * p[j] - l] = false
			}
		}
		if l == 1 {
			isPrime[0] = false
		}
		for j := 0;j < bound;j++ {
			if isPrime[j] {
				fmt.Println(j + l)
			}
		}
	}
}

