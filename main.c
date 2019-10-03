#include<stdio.h>
#include<memory.h>
#include<stdio.h>
#include<string.h>//strcmp(),strcat()
#include<stdlib.h>//rand()
#include<time.h>//time(0)
#include<ctype.h>
#include "PS_SHA_256.c"
#include "aes.c"

#define MAX_LIMIT 1000





void signup(char *username, char *password);
int verifyPassword(int ,char *);
int verifyUsername(char *);
char* generateSalt();
char salt[5];
char* getSalt(int sNo);
//void file_encrypt();
//uc* struprr(uc *);




int main()
{
    int choice,check;
    char username[50],password[50];


    printf("\n**************Password Security System******************************\n");
    printf("\n**************1. Signin(Existing User)****************************** \n");
    printf("\n**************2. Signup(New User)*********************************** \n");
    printf("\n******************************************************************** \n");


    scanf("%d",&choice);

    if(choice==1)
    {
        int sNo;
        printf("\n Enter your Username:\n");
        printf("\n**********************\n");
        scanf("%s",username);
        sNo=verifyUsername(username);
        if(sNo)
        {
            printf("\n Username verified.\n");
            printf(" \n******************** \n");
            printf("\n Enter Your Password:\n");
            printf("\n************************ \n");
            scanf("%s",password);

           if(verifyPassword(sNo,password))
            {
                printf("\n Login Successful\n");
                printf("\n******************\n");

            }
            else
            {
                printf("\n Wrong Password\n");
                printf("\n******************\n");

            }
        }
        else
        {
            printf("No such user exists.\n");
            printf("\n******************\n");
        }

    }

    else if(choice==2)
    {
       reu: printf("\n Enter your Username:\n");
        printf("\n**********************\n");
        scanf("%s",username);
        check= (int)(username[0]);
        if(strlen(username)<3 || (check>=48 &&check <=57) )
           {
               printf("username should be of at least 3 characters or should not start with a number re-enter \n");
               goto reu;
           }

        rep:printf("\n Enter Your Password:\n");
        printf("\n************************ \n");
        scanf("%s",password);
        if(strlen(password)<8)
        {
            printf("Your password is too weak..!!Enter password of atleast 8 characters..\n ");
            goto rep;
        }

        signup(username,password);
        printf("\n Signed up Successfully:\n");
        printf("\n************************ \n");
    }

    else
    {
        printf("Invalid choice! Try again.");
        printf("\n************************ \n");
    }

    //file_encrypt();
    return 0;
}




/*uc* struprr(uc *h1)
{
    int i;printf("Converting to upper case \n\n");char ch;
    for(i=0;i<32;i++)
    {
        h1[i]=toupper(h1[i]);
        printf("%02x ",ch);
        //printf("%c ",toupper("a"));
    }
        for(i=0;i<32;i++)
    {
        //h1[i]=toupper(h1[i]);
        printf("%02x ",h1[i]);
        //printf("%c ",toupper("a"));
    }

    return h1;
} */

char* generateSalt()
{
    srand(time(0));
    short index;
    int i;
    FILE *fp_salt_directory;
    char arr[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q'
    ,'r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9',
    'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    for (i=0;i<4;i++)
    {
        index=rand()%62;
        salt[i]=arr[index];
    }
    salt[4]='\0';
    fp_salt_directory=fopen("salt_directory.txt","a");
    fputs(salt,fp_salt_directory);
    fputs("\n",fp_salt_directory);
    fclose(fp_salt_directory);

    return salt;
}


void signup(char *username,char *password)
{
    char *salt_pointer,buf=0;;uc hash[32],h2[32], *h1, chh =' ';
    int i,num;
    SHA2 ptr;
    memset(hash,0,sizeof(hash));

    FILE *fp_user_directory,*fp_pwd_directory1,*fp_backup;
    FILE *fp_pwd_directory;
    fp_user_directory=fopen("user_directory.txt","a");
    fputs(username,fp_user_directory);
    fputs("\n",fp_user_directory);
    fclose(fp_user_directory);

      salt_pointer=generateSalt();
    //printf("Salt pointer is initilized \n\n");

      strcat(password,salt_pointer);
    //printf("password is modified %s salt \n\n",password);
      fp_pwd_directory1=fopen("PWD.txt","a");
      fputs(password,fp_pwd_directory1);
      fputs("\n",fp_pwd_directory1);
      fp_backup=fopen("User_Backup.txt","a");
      fputs(username,fp_backup);
      fputs("\n",fp_backup);
      fclose(fp_backup);


    // Hash one
      initilize(&ptr);
      update(&ptr,password,strlen(password));
      data_final(&ptr,hash);
      //printf("Printng the contents using standard hash function for storing purpose \n\n");
     //h1=print_hash(hash);
      //h1= struprr(h1);


    fp_pwd_directory=fopen("pwd_directory.txt","a");
    fputs(hash,fp_pwd_directory);
    fputs("\n",fp_pwd_directory);
    //fprintf(fp_pwd_directory,"%02x",h1);
    fclose(fp_pwd_directory);
    fclose(fp_pwd_directory1);

    //fp_pwd_directory=fopen("pwd_directory.txt","r");

    //printf("Printing hash after returning from SHA2 function \n\n");

    /*for(i=0;i<32;i++)
    {
      //h1[i]= fscanf(fp_pwd_directory,"%02x",h2);
       chh+=h1[i];
       //strcat(chh,h1[i]);
       printf("%x ",chh);

      //printf("%02x",h1[i]);

    }
    printf("\n");

    /*for(i=0;i<32;i++)
    {
      //h1[i]= fscanf(fp_pwd_directory,"%02x",db_pwd);
      printf("%02x ",h1[i]);

    } */


}



int verifyUsername(char *user_query)
{
    int sNo=0;
    char db_username[50];
    FILE *fp_user_directory;
    fp_user_directory=fopen("user_directory.txt","r");

    while(fscanf(fp_user_directory,"%s",db_username)!=EOF)
    {
        sNo++;
        if(strcmp(db_username,user_query)==0)
        {
            fclose(fp_user_directory);
            return sNo;
        }
    }
    fclose(fp_user_directory);
    return 0;
}



int verifyPassword(int sNo,char *pwd_query)
{
    int i;
    char *hash_query;char db_salt[5];SHA2 ptr;uc hash[32],*h1 ,h2[32],db_pwd[50];
    FILE *fp_pwd_directory,*fp_pwd_directory1;FILE *fp_salt_directory;
    memset(hash,0,sizeof(hash));
    memset(h2,0,sizeof(h2));
    memset(db_pwd,0,sizeof(db_pwd));


    fp_salt_directory=fopen("salt_directory.txt","r" );
    fp_pwd_directory1=fopen("PWD.txt","r" );
    for(i=0;i<sNo;i++)
    {
            fscanf(fp_salt_directory,"%s",db_salt);
             fscanf(fp_pwd_directory1,"%s",db_pwd);
    }

    strcat(pwd_query,db_salt);
    //hash_query=generate_hash(pwd_query);

    // Hash one
      initilize(&ptr);
      update(&ptr,pwd_query,strlen(pwd_query));
      data_final(&ptr,hash);

      //h1= print_hash(hash);
     // printf(" \n\n Printng the contents using standard hash function matching purpose in verification function \n\n");


    //fp_pwd_directory=fopen("pwd_directory.txt","r");
    //printf(" \n %s \n",h1);

    /*for(i=0;i<32;i++)
    {
      h2[i]= fscanf(fp_pwd_directory,"%02x",db_pwd);
      //printf("%02x",h1[i]);

    }*/
    //printf("\n\n printing contents from file \n\n");
    //fscanf(fp_pwd_directory,"%s",db_pwd);
    //printf("%s \n",db_pwd);

    /*for(i=0;i<32;i++)
    {
      //h1[i]= fscanf(fp_pwd_directory,"%02x",db_pwd);
      printf("%02x ",h2[i]);

    } */


    if(strcmp(pwd_query,db_pwd)==0)
        {
            fclose(fp_pwd_directory1);
            return 1;
        }

    /*for(i=0;i<sNo;i++)
    {
        fscanf(fp_pwd_directory,"%s",db_pwd);
        if(strcmp(db_pwd,hash)==0)
        {
            fclose(fp_pwd_directory);
            return 1;
        }
    } */
    fclose(fp_pwd_directory1);
    return 0;
}
/*int main()
{
    uc text1[MAX_LIMIT],hash[32];
    printf("Enter your data yo be hashed \n");
    gets(text1);


   int idx;
   SHA2 ptr;

   // Hash one
   //initilize(&ptr);
   //update(&ptr,text1,strlen(text1));
   //data_final(&ptr,hash);
   //print_hash(hash);

   signup("aryan",text1);


   getchar();
   return 0;
}
*/

/*void file_encrypt()
{
    int i,len;

	 // Key size

	// Calculate Nk and Nr from the given Nr value.
	Nk = Nr / 32;
	Nr = Nk + 6;
    fflush(NULL);
    char *buf = malloc(chunk);
    char buff=0;
    FILE *file;
    size_t nread;
    char outword[100000];
    file = fopen("User_Backup.txt", "r");
    if (buf == NULL) {

    }
   if(file)
{
    while ((nread = fread(buf, 1, chunk, file)) > 0) {
    strip(buf);
    fwrite(buf, 1, nread, stdout);


    if (ferror(file)) {

    }
    fclose(file);
}
     len=strlen(buf);
      if(buf[len-1]=='\n')
          buf[--len] = '\0';
          for(i = 0; i<len; i++)
          {
              sprintf(outword+i*2, "%02X", buf[i]);
          }
          printf("\nArray elements are : \n");

          memcpy(temp2,buf,len);
          /*for(i=0;i<len;i++)
          {
              printf("Hex: %#04X\n",temp2[i]);
          }
          printf("\n");
}

	// Copy the Key and PlainText
	for(i=0;i<Nk*4;i++)
	{
		Key[i]=temp[i];
		in[i]=temp2[i];
	}

// The KeyExpansion routine must be called before encryption.
	KeyExpansion();
    /*printf("\n Plaintext:\n");
    for(i=0;i<Nk*4;i++)
	{

		printf("%02x ",in[i]);
	} */
	// The next function call encrypts the PlainText with the Key using AES algorithm.
	//Cipher();


	// Output the encrypted text.
	/*printf("\nHexadecimal after encryption:\n");

	for(i=0;i<Nk*4;i++)
	{

		printf("%02x ",out[i]);
	}
	printf("\n\n");





	FILE *f = fopen("ubackup.txt", "w+");
    if (f == NULL)
    {
    printf("Error opening file!\n");
    exit(1);
    }
    for(i=0;i<Nk*4;i++)
	{
		fprintf(f,"%02x ",out[i]);
	}
   printf("File created : ubackup.txt");
   fclose(f);
   }*/

