#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int check_authentication(char * password) {

  int auth_flag = 0;
  char * password_buffer;
  char * dept;

  password_buffer = (char * ) malloc(16);
  dept = (char * ) malloc(10);

  printf("Your department?");
  gets(dept);

  strcpy(password_buffer, password);

  if (strcmp(password_buffer, "AsiaPacificInst") == 0) {
    if (strcmp(dept, "NSF") == 0) {
      auth_flag = 1;
    }
  }
  if (strcmp(password_buffer, "AsiaPacificUni") == 0) {
    if (strcmp(dept, "TM") == 0) {
      auth_flag = 1;
    }
  }
  return auth_flag;
}
int main(int argc, char * argv[]) {
  char errmsg[512];
  char outbuf[512];
  char user[20];
  printf("Username: ");
  gets(user);
  if (strcmp(user, "Adm1n") == 0) {
    printf("Authorised User\n");
    sprintf(errmsg, "Authorised User %400s", user);
    sprintf(outbuf, errmsg);
  } else {
    printf("Unauthorised User!!\n");
    exit(0);
  }
  if (argc < 2) {
    printf("Usage: %s <password>\n", argv[0]);
    exit(0);
  }
  if (check_authentication(argv[1])) {
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf(" Access Granted.\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  } else {
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("\nAccess Denied.\n");
    printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  }
}