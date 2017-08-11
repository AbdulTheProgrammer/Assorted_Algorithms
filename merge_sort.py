# Abdul's python implementation
        
        def merge(a , b):
          if(len(a) == 0 and len(b) ==0)
              return None
           else if(len(a) == 0 and len(b) > 0 )
             return b 
           else if (len(b) == 0 and len(a) > 0 )
             return a
           else 
          		index1 = 0
            	index2 = 0 
                combined = [] 
             	while index1 < len(a) and index2 < len(b):
                  if a[index1] >= b[index2]:
                  	 combined.append(a[index1])
                    index1 += 1;	
             	  else 
             		combined.append(b[index2])
                    index2 +=1
            # exhaust b   
             if(index1 != len(a)) 
                  for i in range(index2, len(b)) 
                    combined.append(b[i])
             # exhaust a
             if(index2 != len(b)):
                 for i in range(index1, len(a)) 
                    combined.append(a[i])
             return combined
        
        
       def mergesort(int left, int right ,int a[]):
          if(len(a) <= 1)
            return a; 
          
          mid = len(a) / 2 
          
          left_arr = mergesort(left , mid , a[left:mid]) 
          right_arr = mergesort(mid , right , a[mid:right+1])
          
          return merge(left_arr, right_arr)
          