//
//  Print Matrix in spiral form.c
//  
//
//  Created by Md Tahsin Sharif on 2017-07-18.
//
//

#include <stdio.h>

//Matrix Dim m by n

/* Print a matrix in spiral form */

print_spiral(int a[][] ,int m, int n) {
    col_i = 0
    row_i = 0
    edges = 3
    
    
    while(edges)
        while(col_i != m) {
            print("%i", a[row_i][col_i])
            col_i++
        }
    while(row_i != n) {
        print("%i", a[row_i][col_i])
        row_i++
    }
}



///mdtahsinsharif
void spiral_matrix(int arr[][]){
    int dir = RIGHT;
    int RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3;
    int right_bound = arr.length();
    int down_bound = arr[ row_length-1 ].length();
    int left_bound = 0;
    int up_bound = 0;
    
    while(left_bound != right_bound && up_bound != col_height) //base case
    {
        switch dir:
    case RIGHT:
        while ( y <= right_bound)
        {
            print(arr[x][y++]);
        }
        y--;
        dir++;
        row_length--;
        
    case DOWN:
        while(x <= down_bound){
            print(arr[x++][y]);
        }
        x--;
        dir++;
        col_height--;
        
    case LEFT:
        while(y >= left_bound){
            print(arr[x][y--]);
        }
        y++;
        dir++;
        left_bound++;
        
    case UP:
        while(x >= up_bound){
            print(arr[x--][y]);
        }
        x++;
        dir = RIGHT;
        up_bound++;
    }
}


//abhishek
void printSpiral(int rBegin, int rEnd, int colBegin, int colEnd){
    rows = rEnd - RBegin + 1;
    cols = colEnd - colBegin + 1;
    if(rBegin == rEnd && colBegin == colEnd){//done printing
        return;
    }
    else if (rBegin == rEnd){//print horizontally
        for(int i = 0; i < cols; i++){
            printf(arr[rBegin][i]);
        }
    }
    else if (colBegin == colEnd){//print horizontally
        for(int i = 0; i < rows; i++){
            printf(arr[i][colBegin]);
        }
    }
    
    //print right
    for(int i = rBegin; i < cols; i++){
        printf(arr[rBegin][i]);
    }
    //print down
    for(int i = rEnd; i < rows; i++){
        printf(arr[i][colEnd]);
    }
    //print left
    for(int i = colEnd; i > rowBegin; i--){
        printf(arr[rEnd][i]);
    }
    //print up
    for(int i = rows; i > (rowBegin - 1); i--){
        printf(arr[i][colBegin]);
    }
    printSpiral(rBegin - 1, rEnd - 1, colBegin - 1, colEnd - 1);
}
