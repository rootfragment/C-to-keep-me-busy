#include<stdio.h>

char mat[3][3];

void fillmatrix(){
	int i,j;
	char q='1';
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			mat[i][j]=q;
			q++;
}
}
}

void print_matrix(char mat[3][3]){
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%c\t",mat[i][j]);
	}
		printf("\n");
	}
}

int check_win(char mat[3][3]){
	//check rows and cloumns
	int i,j;
	for(i=0;i<3;i++){
		if( mat[i][0] == mat[i][1] && mat[i][1] == mat[i][2]){
			printf("Player %c wins.",mat[i][0]);
			return 0;
		}
		if(mat[0][i] == mat[1][i] && mat[1][i] == mat[2][i]){
			printf("Player %c wins.", mat[0][i]);
			return 0;
		}
	}
	//check diagonals
	if(mat[0][0] == mat[1][1] && mat[1][1] == mat[2][2]){
		printf("Player %c wins.", mat[0][0]);
		return 0;
	}
	if(mat[0][2] == mat[1][1] && mat[1][1] == mat[2][0]){
	printf("Player %c wins.", mat[0][2]);
	return 0;
}
	//return -1 if no win
	return -1;	
}


int main(){
	fillmatrix();
	print_matrix(mat);
	char c;
	int ret,count=0;
	char *p = &mat[0][0];
	while(1){
		printf("Player x choose a number from 1-9");
		scanf(" %c", &c);
		int number = c -'0';
		if(number < 1 || number > 9){
    			printf("Invalid move.\n");
    			continue;
}
		if(*(p + number - 1) == 'x' || *(p + number - 1) == 'o'){
    			printf("Square already occupied.\n");
   			continue;}
		*(p+number-1) = 'x';
		count++;
		ret = check_win(mat);
		if(ret==0){
			break;
		}
		print_matrix(mat);
		printf("Player o choose a number from 1-9");
		scanf(" %c", &c);
		number = c -'0';
		if(number < 1 || number > 9){
    			printf("Invalid move.\n");
    			continue;
}
		if(*(p + number - 1) == 'x' || *(p + number - 1) == 'o'){
    			printf("Square already occupied.\n");
   			continue;}
		*(p+number-1) = 'o';
		count++;
		ret = check_win(mat);
		if(ret==0){
			break;
		}
		print_matrix(mat);
		if(count == 9){
		printf("Draw!\n");
		break;}
	}
	
}
