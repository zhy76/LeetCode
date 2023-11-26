type Node struct {
    key, value int
    pre *Node
    next *Node
}

type LRUCache struct {
    cache map[int]*Node
    capacity int
    dummy *Node
}

func NewNode(key, value int) *Node {
    node := new(Node)
    node.key = key
    node.value = value
    node.pre = node
    node.next = node
    return node
}

func Constructor(capacity int) LRUCache {
    lru := LRUCache{
        capacity: capacity,
        cache: make(map[int]*Node),
        dummy: NewNode(0, 0),
    }
    return lru
}

func (this *LRUCache) remove(node *Node) {
    node.pre.next=node.next
    node.next.pre=node.pre
}

func (this *LRUCache) addToFront(node *Node) {
    node.pre = this.dummy
    node.next = this.dummy.next
    this.dummy.next.pre = node
    this.dummy.next = node
}

func (this *LRUCache) get_node(key int) *Node{
    if node, ok := this.cache[key]; ok {
        this.remove(node)
        this.addToFront(node)
        return node
    }
    return nil
}

func (this *LRUCache) Get(key int) int {
    node := this.get_node(key)
    if node == nil {
        return -1
    }
    return node.value
}


func (this *LRUCache) Put(key int, value int)  {
    node := this.get_node(key)
    if node != nil {
        node.value = value
        return
    }
    
    node = NewNode(key, value)
    this.cache[key] = node
    this.addToFront(node)
    if len(this.cache) > this.capacity {
        tail := this.dummy.pre
        delete(this.cache, tail.key)
        this.remove(tail)
    }
}


/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */