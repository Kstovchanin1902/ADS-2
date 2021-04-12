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
  return 0;
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
  return 0;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, lborder = 0, rborder = len, med = (lborder + rborder) / 2, left = med, right = med;
  for (int i  = 0; i < len; i++) {
      while (rborder >= lborder) {
          med = (lborder + rborder) / 2;
          left = med;
          right = med;
          if (arr[i] + arr[med] == value) {
              while ((arr[i] + arr[left]) == value) {
                  count++;
                  left--;
              }
              count--;
              while ((arr[i] + arr[right]) == value) {
                  count++;
                  right++;
              }
              rborder = lborder-1;
          } else if ((arr[i] + arr[med]) < value) {
                      lborder=med+1;
                  } else if ((arr[i] + arr[med]) > value) {
                              rborder = med-1;
                          }
      }
      rborder = len;
      lborder = i+1;
  }
  return count;
  return 0;
}
