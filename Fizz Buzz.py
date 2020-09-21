class Solution(object):
    def fizzBuzz(self, n):
        result = [0]*n
        for i in range(n):
            number = i+1
            if number%15 == 0:
                result[i] = 'FizzBuzz'
            elif number%3 == 0:
                result[i] = 'Fizz'
            elif number%5 == 0:
                result[i] = 'Buzz'
            else:
                result[i] = str(number)
        return result
            
        
        
