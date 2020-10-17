class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        gList = [[1]];oldRow = 0
        for _ in range(numRows-1):
            arr = gList[oldRow]
            newArr = [1]
            size = len(arr)
            if size >= 2:
                for i in range(size):
                    if i < size and i+1 < size:
                        newArr.append(arr[i]+arr[i+1])
            newArr.append(1)
            gList.append(newArr)
            oldRow += 1
        return gList
                
            
            
        
        
