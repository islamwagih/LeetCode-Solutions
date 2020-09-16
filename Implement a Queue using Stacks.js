/**
 * Initialize your data structure here.
 */
class Node {
  constructor(value){
    this.value = value;
    this.next = null;
    this.prv = null;
  }
}

class Stack {
  constructor(){
    this.top = null;
    this.bottom = null;
    this.length = 0;
  }
  peek(){
    return this.top;
  }
  push(value){
    let newTop = new Node(value);
    if(this.length){
      this.top.next = newTop;
      newTop.prv = this.top;
      this.top = newTop;
    }else{
      this.bottom = newTop;
      this.top = newTop;
    }
    this.length++;
  }
  pop(){
    let oldTop = this.top;
    if(this.top){
      this.top = this.top.prv;
    }
    if(this.top){
      this.top.next = null;
    }
    if(this.length > 0){
      this.length--;
    }
    return oldTop.value;
  }
  isEmpty(){
    if(this.length){
      return false;
    }
    return true;
  }
  size(){
    return this.length;
  }
}

var MyQueue = function() {
    this.pushStack = new Stack();
    this.popStack = new Stack();
    
};

/**
 * Push element x to the back of queue. 
 * @param {number} x
 * @return {void}
 */
MyQueue.prototype.push = function(x) {
    this.pushStack.push(x);
};

/**
 * Removes the element from in front of queue and returns that element.
 * @return {number}
 */
MyQueue.prototype.pop = function() {
    if(!this.popStack.size()){
        while(this.pushStack.size() > 0){
            this.popStack.push(this.pushStack.pop());
        }
    }
    return this.popStack.pop();
    
};

/**
 * Get the front element.
 * @return {number}
 */
MyQueue.prototype.peek = function() {
    if(!this.popStack.size()){
        while(this.pushStack.size() > 0){
            this.popStack.push(this.pushStack.pop());
        }
    }
    return this.popStack.top.value;   
};

/**
 * Returns whether the queue is empty.
 * @return {boolean}
 */
MyQueue.prototype.empty = function() {
    if(this.pushStack.size() == 0 && this.popStack.size() == 0){
        return true;
    }
    return false;   
};

/** 
 * Your MyQueue object will be instantiated and called as such:
 * var obj = new MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */
