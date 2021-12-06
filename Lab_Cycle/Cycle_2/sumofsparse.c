#define MAX_TERMS 100   
struct sparse_matrix{
    int row;
    int col;
    int val;
};
struct sparse_matrix sparse_1[MAX_TERMS];
struct sparse_matrix sparse_2[MAX_TERMS];
int size1,size2;
struct sparse_matrix sparse_sum[MAX_TERMS];
int sumsize;
int matrix1[100][100],matrix2[100][100],matrix_sum[100][100];
const int matrix_rows,matrix_cols;


void printmatrix(int matrix[100][100]){
    for(int i=0;i<matrix_rows;i++){
        for(int j=0;j<matrix_cols;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}
void converttosparse(int matrix[100][100]){
    sparse_1[0].row=sparse_2[0].row=matrix_rows;
    sparse_1[0].col=sparse_2[0].col=matrix_cols;
    int i,j,k1=1,k2=1;
    for(int i=0;i<matrix_rows;i++){
        for(int j=0;j<matrix_cols;j++){
            if(matrix[i][j]){
sparse_1[k1].row=i+1;
sparse_1[k1].col=j+1;
sparse_1[k1].val=matrix[i][j];
            }
            if (matrix2[i][j])
            {
                sparse_2[k2].row = i + 1;
                sparse_2[k2].col = j + 1;
                sparse_2[k2].val = matrix2[i][j];
                k2++;
            }

        }
    }
    size1=k1;
    size2=k2;
    sparse_1[0].val=size1-1;
    sparse_2[0].val=size2-1;
}

void sumahne(){
    sparse_sum[0].row=sparse_1[0].row;
    sparse_sum[0].col=sparse_1[0].col;
    int i=1,j=1,k=1;
    while(i<size1&&j<size2){
        if(sparse_1[i].row==sparse_2[j].row&&sparse_1[i].col==sparse_2[j].col){
            sparse_sum[k].row=sparse_1[i].row;
            sparse_sum[k].col=sparse_1[i].col;
            sparse_sum[k].val=sparse_1[i].val+sparse_2[j].val;
            i++;
            j++;            
        }
        else if(sparse_1[i].row==sparse_2[j].row){
            sparse_sum[k].row=sparse_1[i].row;
            if(sparse_1[i].col<sparse_2[j].col){
                sparse_sum[k].col=sparse_1[i].col;
                sparse_sum[k].val=sparse_1[i].val;
                i++;
            }
            else{
                sparse_sum[k].col=sparse_2[j].col;
                sparse_sum[k].val=sparse_2[j].val;
                j++;
            }          
        }
 else{
     
 }       
    }
}


void main(){
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d",&matrix_rows,&matrix_cols);
    printf("Enter the elements of matrix 1: ");
    for(int i=0;i<matrix_rows;i++){
        for(int j=0;j<matrix_cols;j++){
            scanf("%d",&matrix1[i][j]);
        }
    }
    printf("Enter the number of rows and columns of matrix 2: ");
    int matrix_cols2,matrix_row2;
    scanf("%d %d",&matrix_row2,&matrix_cols2);
    if(matrix_cols2!=matrix_cols||matrix_row2!=matrix_rows){
        printf("The matrices are not compatible for addition");
        return;
    }
    printf("Enter the elements of matrix 2: ");
    for(int i=0;i<matrix_rows;i++){
        for(int j=0;j<matrix_cols;j++){
            scanf("%d",&matrix2[i][j]);
        }
    }

    printmatrix(matrix1);
}