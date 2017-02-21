#include <iostream>

using namespace std;

unsigned int sections[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 25};

unsigned int d(unsigned int section);
unsigned int t(unsigned int section);
unsigned int s(unsigned int section);

unsigned int number_of_checkouts(unsigned int _score);

int main() {
  unsigned int count = 0;
  for (int i = 2; i < 100; i++) {
    count += number_of_checkouts(i);
  }
  cout << "How many distinct ways can a player checkout with a score less than 100? " << endl << count << endl;
  system("pause");
  return 0;
}

unsigned int number_of_checkouts(unsigned int _score) {
  unsigned int count1 = 0;
  unsigned int count2 = 0;
  unsigned int count3 = 0;
  int score1;
  int score2s;
  int score2d;
  int score2t;
  int score3s;
  int score3d;
  int score3t;
  for (unsigned int i = 0; i < 21; i++) {
    score1 = _score;
    score1 -= d(sections[i]);
    if (score1 > 0) {
      
      for (unsigned int j = 0; j < 21; j++) {
        score2s = score1;
        score2s -= sections[j];
        if (score2s == 0) {
          //cout << 'S' << sections[j] << " D" << sections[i] << endl;
          count2++;
        } else if (score2s > 0 && score2s < 61) {
          
          for (unsigned int k = 0; k < 21; k++) {
            score3s = score2s;
            score3s -= sections[k];
            if (score3s == 0) {
              if (sections[k] == sections[j]) {
                //cout << 'S' << sections[k] << " S" << sections[j] << " D" << sections[i] << endl;
                count3++;
              }
              //cout << 'S' << sections[k] << " S" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

          for (unsigned int k = 0; k < 21; k++) {
            score3d = score2s;
            score3d -= d(sections[k]);
            if (score3d == 0) {
              //cout << 'D' << sections[k] << " S" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

          for (unsigned int k = 0; k < 20; k++) {
            score3t = score2s;
            score3t -= t(sections[k]);
            if (score3t == 0) {
              //cout << 'T' << sections[k] << " S" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

        }
      }

      for (unsigned int j = 0; j < 21; j++) {
        score2d = score1;
        score2d -= d(sections[j]);
        if (score2d == 0) {
          //cout << 'D' << sections[j] << " D" << sections[i] << endl;
          count2++;
        } else if (score2d > 0 && score2d < 61) {
          for (unsigned int k = 0; k < 21; k++) {
            score3s = score2d;
            score3s -= sections[k];
            if (score3s == 0) {
              //cout << 'S' << sections[k] << " D" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

          for (unsigned int k = 0; k < 21; k++) {
            score3d = score2d;
            score3d -= d(sections[k]);
            if (score3d == 0) {
              if (sections[k] == sections[j]) {
                //cout << 'D' << sections[k] << " D" << sections[j] << " D" << sections[i] << endl;
                count3++;
              }
              //cout << 'D' << sections[k] << " D" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

          for (unsigned int k = 0; k < 20; k++) {
            score3t = score2d;
            score3t -= t(sections[k]);
            if (score3t == 0) {
              //cout << 'T' << sections[k] << " D" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }


        }
      }

      for (unsigned int j = 0; j < 20; j++) {
        score2t = score1;
        score2t -= t(sections[j]);
        if (score2t == 0) {
          //cout << 'T' << sections[j] << " D" << sections[i] << endl;
          count2++;
        } else if (score2t > 0 && score2t < 61) {
          for (unsigned int k = 0; k < 21; k++) {
            score3s = score2t;
            score3s -= sections[k];
            if (score3s == 0) {
              //cout << 'S' << sections[k] << " T" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

          for (unsigned int k = 0; k < 21; k++) {
            score3d = score2t;
            score3d -= d(sections[k]);
            if (score3d == 0) {
              //cout << 'D' << sections[k] << " T" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }

          for (unsigned int k = 0; k < 20; k++) {
            score3t = score2t;
            score3t -= t(sections[k]);
            if (score3t == 0) {
              if (sections[k] == sections[j]) {
                //cout << 'T' << sections[k] << " T" << sections[j] << " D" << sections[i] << endl;
                count3++;
              }
              //cout << 'T' << sections[k] << " T" << sections[j] << " D" << sections[i] << endl;
              count3++;
            }
          }



        }
      }

    } else if (score1 == 0) {
      //cout << 'D' << sections[i] << endl;
      count1++;
    }
  }
  //cout << "count1: " << count1 << endl;
  //cout << "count2: " << count2 << endl;
  //cout << "count3: " << count3 / 2 << endl;
  unsigned int count = count1 + count2 + (count3 / 2);
  return count;
}

unsigned int d(unsigned int section) {
  return 2 * section;
}

unsigned int t(unsigned int section) {
  return 3 * section;
}

unsigned int s(unsigned int section) {
  return section;
}