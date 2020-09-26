class Solution(object):
    def NOT(self,a):
        return self.add(~a,1)
    def add(self,a,b):
        if not a or not b:
            return a or b
        if not a and not b:
            return 0
        return self.add(a^b,(a&b) << 1)
    def getSum(self, a, b):
        if a >= 0 and b >= 0:
            return self.add(a,b)
        elif a < 0 and self.NOT(a) > b:
            return self.add(a,b)
        elif a < 0 and self.NOT(a) == b:
            return 0
        elif a < 0 and self.NOT(a) < b:
            return self.NOT(self.add(self.NOT(a),self.NOT(b)))
        elif b < 0 and self.NOT(b) == a:
            return 0
        elif b < 0 and self.NOT(b) > a:
            return self.add(a,b)
        else:
            self.NOT(self.add(self.NOT(a),self.NOT(b)))
            
        
