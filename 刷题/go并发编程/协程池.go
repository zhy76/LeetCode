package main
import(
	"fmt"
	// "runtime"
	"sync"
	"time"
)

type Task interface {
	execute()
}

type Pool struct {
	TaskChannel chan Task
}

func NewPool(size int) *Pool {
	p := Pool{
		TaskChannel: make(chan Task, size),
	}
	return &p
}

func (p *Pool) Run(wg *sync.WaitGroup) {
	for task := range p.TaskChannel {
		task.execute()
	}
	wg.Done()
}

func (p *Pool) AddTask(task Task) {
	p.TaskChannel <- task
}

type MyTask struct {
	name string
}

func (t *MyTask) execute() {
	fmt.Println("Executing task", t.name)
	time.Sleep(1 * time.Second)
}

func main() {
	// runtime.GOMAXPROCS(runtime.NumCPU())
	p := NewPool(10)
	var wg sync.WaitGroup
	wg.Add(10)
	for i := 0; i < 10; i++ {
		go p.Run(&wg)
	}
	for i := 0; i < 10; i++ {
		t := MyTask{name: fmt.Sprintf("Task %d", i)}
		p.AddTask(&t)
	}
	close(p.TaskChannel)
	wg.Wait()
}
