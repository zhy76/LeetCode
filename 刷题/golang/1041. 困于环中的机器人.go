func isRobotBounded(instructions string) bool {
	x, y, d := 0, 0, 0
	dir := [][]int{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}
	for _, ins := range instructions {
		if ins == 'G' {
			x += dir[d%4][0]
			y += dir[d%4][1]
		} else if ins == 'L' {
			d = (d + 3) % 4
		} else {
			d = (d + 1) % 4
		}
	}
	return d != 0 || (x == 0 && y == 0)
}