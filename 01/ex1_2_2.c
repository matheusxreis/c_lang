#include<stdio.h>
#include<stdlib.h>

void execute();
int media(int arr[], int size);

int main() {
  

  execute();
  
  return 1;
};


void execute() {

  // leitura de uma semana, dê 180 diferentes latitudes (-90 até 90);
  int reads[181][7];
  int medias[181];


  for(int i = 0; i<=180; i++){
    for(int j = 0; j<= 6; j++){
      reads[i][j] = rand() % 40;
    }
  }


  int j = 0;

  // printando médias de cada latitute
  printf("| latitude | temperatura |\n");
  for(int i = -90; i<=90; i++, j++){ 
    int med =  media(reads[j], sizeof(reads[j])/sizeof(reads[j][0]));
    medias[j] = med; 
    printf("|    %d    |     %d     |\n", i,med);
    
  }

  j = 0;
  
  printf("hemisfério sul\n");
  printf("| temperatura média |\n");
  printf("| %d |\n", media(medias, 89));  
  printf("hemisfério norte\n");
  printf("| temperatura média |\n");
  printf("| %d |\n", media(medias+91,89)); 

}


int media(int arr[], int size) {
  int result = 0;
  for(int i = 0; i<=size-1; result += arr[i++]);
  return result/size;
}
