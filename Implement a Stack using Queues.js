/**
 * Initialize your data structure here.
 */
class Node {
  constructor(value) {
    this.value = value;
    this.next = null;
    this.prv = null;
  }
}

class myQueue {
  constructor(){
    this.first = null;
    this.last = null;
    this.length = 0;
  }
  peek() {
    return this.first;
  }
  enqueue(value){
    let newNode = new Node(value);
    if(this.length === 0){
      this.first = newNode;
      this.last = newNode;
    }else{
      newNode.next = this.last;
      this.last.prv = newNode;
      this.last = newNode;
    }
    this.length++;
    return this.length;
  }
  dequeue(){
    if(!this.length){
      return null;
    }
    let holdingNode = this.first;
    if(this.length === 1){
        this.first = this.last = null;
        this.length--;
        return holdingNode.value;
    }
    this.first = this.first.prv;
    this.first.next = null;
    this.length--;
    holdingNode.prv = null;
    return holdingNode.value;
  }
  isEmpty(){
    if(this.length){
      return false;
    }
    return true;
  }
}

var MyStack = function() {
    this.fstQueue = new myQueue();
    this.secQueue = new myQueue();
    
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    this.fstQueue.enqueue(x);
};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    /*pop q1 until size is 1(last item)*/
    while(this.fstQueue.length > 1){
        this.secQueue.enqueue(this.fstQueue.dequeue());
    }
    let holdingValue = this.fstQueue.dequeue();
    while(this.secQueue.length > 0){
        this.fstQueue.enqueue(this.secQueue.dequeue());
    }
    return holdingValue;
};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.fstQueue.last.value;   
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    if(this.fstQueue.length > 0){
        return false;
    }
    return true;   
};

/** 
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
