import Foundation

// Total number of lattice paths on a n * n block-based grid with the restriction that all paths must move down, or to the right
// All paths must start at (0,0) - the upper-left corner of the n*n grid, and (n,n) is the bottom-right corner of the grid

// The number of ways to get to any point (x, y) on the lattice grid is the sum of the number of ways to get to its incoming edges



// Time AND Space complexity O((n+1)*(n+1))
func totalNumberOfLatticePathsForN(_ n: Int) -> Int {
    var numberOfRoutesToPoint = Array(repeating: [Int](), count: n+1)
    for index in 0...n {
        numberOfRoutesToPoint[index] = Array(repeating: 0, count: n+1)
    }
    for index in 1...n {
        numberOfRoutesToPoint[index][0] = 1
        numberOfRoutesToPoint[0][index] = 1
    }
    for index in 1...n {
        for innerIndex in 1...n {
            numberOfRoutesToPoint[index][innerIndex] = numberOfRoutesToPoint[index-1][innerIndex] + numberOfRoutesToPoint[index][innerIndex-1]
        }
    }
    return numberOfRoutesToPoint[n][n]
}

print(totalNumberOfLatticePathsForN(20))


/*
// Horrible solution (time AND space complexity worse than 2^n):
func totalPathsToPoint(_ a: Int, _ b: Int) -> Int {
    if a == 0 {
        return 1
    }
    if b == 0 {
        return 1
    }
    return totalPathsToPoint(a-1, b) + totalPathsToPoint(a, b-1)
}

func totalNumberOfLatticePathsForN(_ n: Int) -> Int {
    if n < 0 { return -1 }
    return totalPathsToPoint(n, n)
}



print(totalNumberOfLatticePathsForN(20))
*/
