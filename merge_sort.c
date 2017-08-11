  /*Merge Sort*/
  
  
  
  
  void merge(int* array, int left_ind, int mid, int right_ind){
	 int left_size = (mid - left_ind + 1);
  	 int right_size = (right_ind - mid + 1);
  	 
  	 int left[left_size], right[right_size];
     for(int i = 0; i < left_size; i++){
  		left[i] = array[i];
     }
  	 for(int j = 0; j < right_size; j++){
  	    right[j] = array[mid+i];
     }
  	 int x = 0, y = 0;
  	 for (int k=left_index; k < right_ind; k++){
       	if (x < left.length && left[x] <= right[y]){
          array[k] = left[x];
          x++;
        } else if(y < right.length && left[x] > right[y]) {
          array[k] = right[y];
          y++;
        } else if (x < left_size){
          array[k] = left[x];
        } else if (y < right_size){
          array[k] = right[x];	
        }
       	k++;
     }
    
     
  
     
  }
  
  void merge_sort(int* array, int left_ind, int right_ind){
  	 
     int mid = (right_ind - left_ind)/2;
     if (left_ind < right_ind){
       merge_sort(array, left_ind, mid);
  	   merge_sort(array, mid+1, right_ind);
      
       merge(array, left_ind, mid, right_ind);
     }
  }
  
  
  
  
  
    
  
        
        
        
 /*       
  
  
  Find the kth smallest value in unsorted array
  
  
  brute force 
  sort it lol 
  heapify the array and pop the top k times 
  klog(n)
  Merge sort + k times searcg 
  knlog(n)
  
  2nd smallest 
  
  = 3 
  
  4 th smallest
  
  length = 5 
  
  
  5 3 7 8 2 
  
  
  */
        
        
        
        
        