class MyQueue:
    def __init__(self):
        self.s = []
        self.z = []

    def push(self, x):
        self.s.append(x)

    def pop(self):
        if not self.s:
            print("Queue is empty. Cannot pop.")
            return -1
        
        while len(self.s) > 1:
            self.z.append(self.s.pop())
            
        ans = self.s.pop()
        while self.z:
            self.s.append(self.z.pop())
            
        return ans

    def front(self):
        if not self.s:
            print("Queue is empty. Cannot get front.")
            return -1
        
        while len(self.s) > 1:
            self.z.append(self.s.pop())
        
        ans = self.s[0]
        while self.z:
            self.s.append(self.z.pop())
        
        return ans

    def empty(self):
        return not self.s


q = MyQueue()
q.push(1)
q.push(2)
q.push(3)
print(q.pop())  
print(q.front())
print(q.empty())