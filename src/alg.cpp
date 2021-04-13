// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i<(len-1); i++) {
      for (int j = i + 1; j < len; j++) {
          if ((arr[i]+arr[j])==value) {
              count++;
          }
      }
    }
  return count;
  
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, num = len - 1;
    while ((arr[0]+arr[num])>value) {
        num--;
    }
    for (int i = 0; i<(num+1); i++) {
        for (int j = i + 1; j< (num+1); j++) {
            if ((arr[i]+arr[j])==value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  int count=0, lborder=0, rborder=len, med=(lborder+rborder)/2, left=med, right=med;
    for (int i=0; i<len; i++){
      while (rborder>=lborder){
        med=(lborder+rborder)/2;
        left=med-1;
        right=med+1;
        if (arr[i]+arr[med]==value){
          cout<<arr[i]<<" + "<<arr[med]<<" == ";
          if (i!=med) {
            count++;
          }
          while (((arr[i]+arr[left])==value)&&(i!=left)){
            count++;
            left--;
          }
          while (((arr[i]+arr[right])==value)&&(i!=right)){
            count++;
            right++;
          }
          rborder=lborder-1;
       } else if ((arr[i]+arr[med])<value){
                lborder=med+1;
              } else if ((arr[i]+arr[med])>value){
                        rborder=med-1;
                     }
        }
        arr[i]=value+1;
        rborder=len;
        lborder=0;
    }
    return count;
}
