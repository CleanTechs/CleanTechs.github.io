#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#define SIZE 3 /*���峣��SIZE�����Ժ���޸�*/

struct student /*����һ���ṹ��������ѧ������Ϣ*/

{

    int number; /*ѧ��*/

    char name[20];/*����*/

    char xueyuan[20];/*ѧԺ*/

    int cla;/*�༶*/

    int score[3];/*����*/

    int sum;/*�ܷ�*/

    int average;/*ƽ����*/

}stu[SIZE];

 

void menu();/*���ò˵�����*/

void write();/*������Ϣ*/

void save(int x);/*����stud.dat�ļ�����*/

void SaveOneStudent(int i);/*����һ��ѧ����Ϣ*/

void SaveAllStudent(int n);/*����ȫ��ѧ����Ϣ*/

void inturn (struct student c[]);/*���ڶ�ѧ������Ϣ��ѧ������ĺ���*/

void save2();/*����������Ϣ����student.dat�ļ���*/

int AddStudent(int n);/*����ѧ����Ϣ*/

void InputOnestudent(int i);/*����һ��ͬѧ��Ϣ*/

int DelStudent(int n);/*ɾ��ѧ����Ϣ*/

void ModifyStudent(int n);/*�޸�ѧ����Ϣ*/

void OutputOneStudent(int i);/*��ѯһ��ѧ����Ϣ*/

void SearchMenu(int n);/*��ѯѧ����Ϣ����*/

void SearchNumber(int n);/*��ѧ�Ų�ѯѧ����Ϣ*/

void SearchName(int n);/*��������ѯѧ����Ϣ*/

void SearchXueyuan(int n);/*������ѧԺ��ѯѧ����Ϣ*/

void SearchCla(int n);/*�����ڰ༶��ѯѧ����Ϣ*/

void tongji();/*ѧ����Ϣͳ�Ʋ���*/

void tongji2();/*ͳ�Ʋ������ʲ���*/

void zfsc();/*�ܷ��������*/

void avecz();/*��ƽ����ͳ����������*/

void avecz();/*��ƽ����ͳ����������*/

void search();/*������߳ɼ�����*/

void tongji2();/*ͳ�Ʋ������ʲ���*/

void read();/*��ȡstudent.dat�ļ��ļ���ѧ������Ϣ*/

 

/*������************************************************************************************/

int main(void)

{

    int n=SIZE;

    int choice;/*�û�ѡ�����*/

    printf("*******************************************************************************\n");

    printf("*                                                                             *\n");

    printf("*          Hwadee            &ѧ���ɼ��ļ�����&          Hwadee               *\n");

    printf("*                                                                             *\n");

    printf("*******************************************************************************\n\n\n");

    printf("******************************���ӭʹ�á��*********************************");

    while (1)

    {

         menu();/*���ò˵������γɲ�������*/

         printf("��ѡ��:");

         scanf("%d", &choice);

         if ( choice==0 )

         {

              printf("\t\t\t\tллʹ��!!!");

              break;

          }

       switch(choice) /*����ѡ��ʵ�ֹ��ܲ�ͬ�Ĺ���*/

       {  

            case 1:

                write();

              inturn(stu);

              save(SIZE);

                break;

            case 2:

              AddStudent(n);

                break;

           case 3:

              DelStudent(n);

              break;

           case 4:

                ModifyStudent(n);

              break;

           case 5:

              SearchMenu(n);

              break;

           case 6:

              tongji();

              break;

           case 0:

              printf("\nллʹ��!�ټ�!\n");

           default:

              printf("\n��������!������ѡ��!\n");

       }/*����switch*/

    }/*����while*/

}



/*�˵�����*************************************************************************************/

void menu()

{

    printf("************�������������***********\n");/*ѡ���ܲ˵�*/

    printf("*************************************\n");

    printf("1.ѧ���ɼ�д�뼰����\n");

    printf("2.����ѧ����Ϣ\n");

    printf("3.ɾ��ѧ����Ϣ\n");

    printf("4.�޸�ѧ����Ϣ\n");                             

    printf("5.��ѯѧ����Ϣ\n");

    printf("6.ѧ���ɼ�ͳ�Ʋ���\n");

    printf("0.�˳�ϵͳ\n");

    printf("**************************************\n");

}

 

/*д�뺯��*************************************************************************************/

void write()

{

    int i;/*��������*/

    for(i=0;i<SIZE;i++)

    {

        printf("ѧ��:");

        scanf("%d",&stu[i].number);

        printf("����:");

        scanf("%s",&stu[i].number);

        printf("ѧԺ:");

        scanf("%s",&stu[i].xueyuan);

        printf("�༶:");

        scanf("%d",&stu[i].cla);

        printf("����:");

        scanf("%d",&stu[i].score[0]);

        printf("Ӣ��:");

        scanf("%d",&stu[i].score[1]);

        printf("C����:");

        scanf("%d",&stu[i].score[2]);

        stu[i].sum=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]);/*�����ܳɼ�*/

        printf("�ܳɼ�:%d",stu[i].sum);

        stu[i].average=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;/*����ƽ���ɼ�*/

        printf("ƽ���ɼ�:%d\n",stu[i].average);

    }

}

 

/*������**************************************************************************************/

void inturn(struct student m[])

{

    int i,j;/*��������*/

    struct student temp;/*�м���� ����Ϊ�ṹ��*/

    for(i=0;i<SIZE-1;i++) /*����ð������Խṹ�������������*/

    for (j=i+1;j<SIZE-i-1;j++)

    {

       if(m[i].number>m[j].number)

       {

           temp=m[i];

           m[i]=m[j];

           m[j]=temp;

       }

    }

    printf("\n������ѧ����Ϣ:\n\n");

    for (i=0;i<SIZE;i++)

    {

        printf("ѧ��%d\t����%s\tѧԺ%s\t�༶%d\t����%d\tӢ��%d\tC����%d\t�ܳɼ�%d\tƽ���ɼ�%d\n\n",i+1,stu[i].number,stu[i].name,stu[i].xueyuan,stu[i].cla,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);

    }/*���������ѧ����Ϣ*/ 

}

/*д���ļ�*************************************************************************************/

void save(int x)

{

    FILE *fp;/*�����ļ�ָ���������ļ���������*/

    int i;

    if((fp=fopen("student.dat","rb+"))==NULL)/*�Զ����ƶ���д��ʽ���ļ�*/

    {

        printf("cannot open file\n");

       exit(1);

    }

    for(i=0;i<SIZE;i++)

        if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)

            printf("file write error\n");

    fclose(fp);

    printf("\n��Ϣ����ɹ�!��ϲ!!\n");

}

 

/*����һ��ѧ����Ϣ******************************************************************************/

void SaveOneStudent(int i)

{

    FILE *fp;

    if((fp=fopen("student.dat","rb+"))==NULL)/*�Զ����ƶ���д��ʽ���ļ�*/

    {

        printf("�ļ���ʧ��!\n");

        exit(1);

    }

    fseek(fp,i,0);/*�ļ�ָ�붨λ����i��ѧ��*/

    fwrite(&stu[i],sizeof(struct student),1,fp);/*����i��ѧ����Ϣд���ļ�*/

    fclose(fp);

}

 

/*����ȫ��ѧ����Ϣ******************************************************************************/

void SaveAllStudent(int n)/*����ȫ��ѧ����Ϣ*/

{

    FILE *fp;

    if((fp=fopen("student.dat","wb"))==NULL)/*�Զ�����д��ʽ���ļ�*/

    {

        printf("�ļ���ʧ��!\n");

        exit(1);

    }

    fwrite(stu,sizeof(struct student),n,fp);/*������stu��ȫ��ѧ����Ϣд���ļ�*/

    fclose(fp);

}

 

/*��������ѧ����Ϣ���뵽������ļ���**********************************************************/

void save2()

{

    FILE *fp;

    int i;

    if((fp=fopen("stud.dat","rb+"))==NULL)/*�Զ����ƶ���д��ʽ���ļ�*/

    {

        printf("�ļ���ʧ��!\n");

        exit(1);

    }

    for (i=0;i<SIZE;i++)

        if (fwrite(&stu[i],sizeof(struct student),1,fp)!=1)

        printf("file write error\n");

    fclose(fp);/*��ȡ��Ϲر��ļ�*/

}

 

/*����ѧ����Ϣ*********************************************************************************/

int AddStudent(int n)

{

    char c='y';

    FILE *fp;

    if((fp=fopen("student.dat","ab"))==NULL)/*�Զ�����׷�ӷ�ʽ���ļ�*/

    {

        printf("�ļ���ʧ��!\n");

        exit(1);

    }

    while(c=='y')

    {

        printf("\n������Ҫ���ӵ�ͬѧ����Ϣ:");

        InputOnestudent(n);/*���ú��������n��ѧ����Ϣ*/

       fwrite(&stu[n],sizeof(struct student),1,fp);/*����n��ѧ����Ϣ�������ļ�*/

       n++;/*ѧ����������1*/

        printf("\n������������ͬѧ��Ϣ��?\n");

        printf("ȷ������ɾ���밴y��������ɾ���밴n\n");

       c=getchar();

        getchar();

    }/*����while*/

    printf("\n�����������!\n");

    getchar();

    fclose(fp);

    return(n);

}

 

/*����һ��ͬѧ��Ϣ*****************************************************************************/

void InputOnestudent(int i)

{

    printf("ѧ��\t����\tѧԺ\t�༶\t����\tӢ��\tC����\n");

    scanf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t\n",&stu[i].number,stu[i].name,stu[i].xueyuan,&stu[i].cla,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);      

    stu[i].sum=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]);/*�����ܳɼ�*/      

    stu[i].average=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;/*����ƽ���ɼ�*/

}

 

/*ɾ��ѧ����Ϣ*********************************************************************************/

int DelStudent(int n)

{

    int i,k=-1,x;

    char c1='y',c2;

    while(c1=='y')

    {

       c2='n';

        printf("\n������Ҫɾ����ͬѧ��ѧ��:");

        scanf("%d",&x);

        for(i=0;i<n;i++)

           if(x==stu[i].number)

           {

               k=i;/*�ҵ�Ҫɾ����ͬѧѧ�ţ�����k�������±�*/

               break;

           }

        if(k<0)/*k<0��ʾ��������û���ҵ�����ѧ�Ŷ�Ӧ��ѧ��*/

            printf("\n����ѧ����������������!");

        else

       {

            printf("\n��ͬѧ��Ϣ����:\n");

            InputOnestudent(k);

            printf("\nȷ��ɾ��?\n");

            printf("ȷ������ɾ���밴y��������ɾ���밴n\n");

           c2=getchar();

           getchar();

           if(c2=='y')/*c2Ϊy,��ʾȷ������ɾ������*/

           {

               for(i=k;i<n;i++)

                  stu[i]=stu[i+1];/*ɾ����k��ѧ����Ϣ*/

               n--;/*ѧ��������1*/

               printf("ɾ���ɹ�!��ϲ!!\n");

           }

           else

               printf("\nȡ��ɾ��!\n");

            printf("\n����ɾ��������?");

            printf("\n����ɾ���밴y��������ɾ���밴n\n");

           c1=getchar();

           getchar();

       }

    }/*����while*/

    save(n);

    printf("\n�����������!\n");

    getchar();

    return(n);

}

 

/*�޸�ѧ����Ϣ********************************************************************************/

void ModifyStudent(int n)

{

    struct student temp;

    int k=-1,x,i;

    char c1='y',c2;

    while(c1=='y')

    {

       c2='y';

        printf("\n������Ҫ�޸ĵ�ͬѧ��ѧ��:");

        scanf("%d",&x);

        for(i=0;i<n;i++)

           if(x==stu[i].number)

           {

               k=i;/*�ҵ�Ҫ�޸ĵ�ͬѧѧ�ţ�����k�������±�*/

               break;

           }

        if(k<0)/*k<0��ʾ��������û���ҵ�����ѧ�Ŷ�Ӧ��ѧ��*/

            printf("\n����ѧ����������������!");

        else

       {

            printf("������Ҫ�޸�ѧ���޸ĺ�ĵ���Ϣ\n");

            printf("ѧ��\t����\tѧԺ\t�༶\t����\tӢ��\tC����\t\n");

            scanf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t\n",&temp.number,stu[i].name,temp.xueyuan,&temp.cla,&temp.score[0],&temp.score[1],&temp.score[2]);      

           temp.sum=(temp.score[0]+temp.score[1]+temp.score[2]);/*�����ܳɼ�*/      

           temp.average=(temp.score[0]+temp.score[1]+temp.score[2])/3;/*����ƽ���ɼ�*/

            stu[k]=temp;/*�޸ĸ�ѧ����Ϣ*/

            printf("\n�޸ĳɹ�!��ϲ!!\n");

           break;

       }

        SaveAllStudent(k);/*�����޸ĺ��ѧ����Ϣ*/

        printf("\n�����޸Ĳ�����?");

        printf("\n�����޸��밴y���������޸��밴n\n");

       c1=getchar();

        getchar();

    }/*����while*/

    printf("\n�����������!\n");

    getchar();

}

 

/*��ѯһ��ѧ����Ϣ**********************************************************************************/

void OutputOneStudent(int i)

{

    printf("ѧ��:%d  ����:%s  ѧԺ:%s  �༶:%d\n",stu[i].number,stu[i].name,stu[i].xueyuan,stu[i].cla);

    printf("����:%d  Ӣ��:%d  C����:%d  �ܷ�:%d  ƽ����:%d\n",stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);

}

 

/*��ѯѧ����Ϣ����*********************************************************************************/

void SearchMenu(int n)

{

    int selet;

    while(1)

    {

        printf("**********************************************************\n");

        printf("******************** ��ӭ�����ѯϵͳ  *******************\n");    

        printf("**********************************************************\n");

        printf("\n");

        printf("*********************  �������������  *******************\n");/*ѡ���ܲ˵�*/

        printf("**********************************************************\n");

        printf("1.��ѧ�Ų�ѯ\n");

        printf("2.��������ѯ\n");

        printf("3.��ѧԺ��ѯ\n"); 

        printf("4.���༶��ѯ\n");

        printf("0.�������˵�\n");     

        printf("**********************************************************\n");

        printf("���������ѡ��:");

        scanf("%d",&selet);

       getchar();

        switch(selet)

       {

           case 1:

              SearchNumber(n);

              break;

           case 2:

              SearchName(n);

              break;

           case 3:

              SearchXueyuan(n);

              break; 

           case 4:

              SearchCla(n);

              break;

           case 0:

              return;

           default:

              printf("�������!����������!\n");

       }

    }/*����while*/

}

 

/*��������ѯѧ����Ϣ*******************************************************************************/

void SearchName(int n)

{

    int i,j,k;

    char xname[20],c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n������ѧ������:");

       gets(xname);

       for(i=0,j=1;i<n;i++)/*��ȷ��ѯ*/

           if(strcmp(stu[i].name,xname)==0)

           {

               k=i;/*�ҵ�Ҫ��ѯ��ͬѧ����,����k�������±�*/

               printf("ѧ��%d����Ϣ:\n",j++);

                OutputOneStudent(k);

                printf("\n�����������!\n");

                getchar();

           }

       if(k==-1)/*k��ʾû�о�ȷ��ѯ���*/

       {

           printf("\nģ����ѯ�������:\n");

           for(i=0,j=1;i<n;i++)

              if(strstr(stu[i].name,xname)!=NULL)/*ģ����ѯ*/

              {

                  k=1;

                   printf("ѧ��%d����Ϣ:\n",j++);

                    OutputOneStudent(k);

                    printf("\n�����������!\n");

                    getchar();

              }

           if(j==1)

                printf("\n��Ǹ!û�и�ѧ����Ϣ!\n");

       }

       printf("������ѯ����ѧ����Ϣ��?");

        printf("\n�����޸��밴y���������޸��밴n\n");

       c=getchar();

        getchar();

    }/*����while*/

    printf("\n�����������!\n");

    getchar();

}

 

/*��ѧ�Ų�ѯѧ����Ϣ*******************************************************************************/

void SearchNumber(int n)

{

    int i,j,k,x;

    char c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n������ѧ��ѧ��:");

       scanf("%d",&x);

       for(i=0,j=1;i<n;i++)

           if(stu[i].number==x)

           {

               k=i;/*�ҵ�Ҫ��ѯ��ͬѧѧ��,����k�������±�*/

               printf("ѧ��%d����Ϣ:\n",j++);

                OutputOneStudent(k);

                printf("\n�����������!\n");

                getchar();

           }

       printf("������ѯ����ѧ����Ϣ��?");

        printf("\n�����޸��밴y���������޸��밴n\n");

       c=getchar();

        getchar();

    }/*����while*/

    printf("\n�����������!\n");

    getchar();

}

 

/*������ѧԺ��ѯѧ����Ϣ***************************************************************************/

void SearchXueyuan(int n)

{

    int i,j,k;

    char xxueyuan[20],c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n������ѧ������ѧԺ:");

       gets(xxueyuan);

       for(i=0,j=1;i<n;i++)

           if(strcmp(stu[i].xueyuan,xxueyuan)==0)

           {

               k=i;/*�ҵ�Ҫ��ѯ��ͬѧ����ѧԺ,����k�������±�*/

               printf("ѧ��%d����Ϣ:\n",j++);

                OutputOneStudent(k);

                printf("\n�����������!\n");

                getchar();

           }

       printf("������ѯ����ѧ����Ϣ��?");

        printf("\n�����޸��밴y���������޸��밴n\n");

       c=getchar();

        getchar();

    }/*����while*/

    printf("\n�����������!\n");

    getchar();

}

 

/*�����ڰ༶��ѯѧ����Ϣ***************************************************************************/

void SearchCla(int n)

{         

    int i,j,k,x;

    char c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n������ѧ�����ڰ༶:");

       scanf("%d",&x);

       for(i=0,j=1;i<n;i++)

           if(stu[i].cla==x)

           {

               k=i;/*�ҵ�Ҫ��ѯ��ͬѧ���ڰ༶,����k�������±�*/

               printf("ѧ��%d����Ϣ:\n",j++);

                OutputOneStudent(k);

                printf("\n�����������!\n");

                getchar();

           }

       printf("������ѯ����ѧ����Ϣ��?");

        printf("\n�����޸��밴y���������޸��밴n\n");

       c=getchar();

        getchar();

    }/*����while*/

    printf("\n�����������!\n");

    getchar();

}

 

/*ѧ����Ϣͳ�Ʋ���*********************************************************************************/

void tongji()

{  

    int x;

    printf("**********************************************************\n");

    printf("******************** ��ӭ����ͳ��ϵͳ  *****************++\n");       

    printf("**********************************************************\n");

    printf("\n");

    printf("************�������������***********\n");/*ѡ���ܲ˵�*/

    printf("*************************************\n");

    printf("1.���ܷ��������\n");

    printf("2.��ƽ����ͳ����������\n");                         

    printf("3.��������߳ɼ�����\n");

    printf("4.��ͳ�Ʋ������ʲ���\n");                             

    printf("0.�������˵�\n");

    printf("**************************************\n");

    printf("���������ѡ��:");

    scanf("%d",&x);/*�û�ѡ�����*/

    while(x>0&&x<6)

    {

        switch(x)

       {

           case 1:

                 zfsc();break;/*ѡ���ܷ��������*/        

             case 2:

                  avecz();break;/*ѡ��ƽ����ͳ����������*/

             case 3:

                  search();break;/*ѡ�񰴲�����߳ɼ�����*/

             case 4:

                  tongji();break;/*ѡ��ͳ�Ʋ������ʲ���*/

             case 0:

                printf("ллʹ��!�ټ�!\n");

               return;/*ѡ���˳�����*/

             default:

                printf("�������!����������\n");/*��ʾ������Ϣ*/

       }

    }

}

 

/*�ܷ��������*************************************************************************************/

void zfsc()

{

    FILE *wj,*fp;

    int i,j;

    struct student temp;

    if((fp=fopen("student.dat","wb"))==NULL)

    {

        printf("�ļ���ʧ��!\n");

       exit(1);

    }

    for(i=0;i<SIZE-1;i++)

        for(j=0;j<SIZE-i-1;j++)

            if(stu[i].sum<stu[j].sum)/*ð�ݷ�����*/

            {

                temp=stu[j];

                stu[j]=stu[i];

                stu[i]=temp;

            }

    if((wj=fopen("student1.dat","wb+"))==NULL)

    {

        printf("�ļ���ʧ��!\n");

       exit(1);

    } 

    else

    {   

         for(i=0;i<SIZE;i++)

             fwrite(&stu[i],sizeof(struct student),1,wj);/*д���ļ�*/

    }

    fclose(fp);

    fclose(wj);

}

 

/*��ƽ����ͳ����������*****************************************************************************/

void avecz()

{

    int i=0,k,m;

    printf("ƽ���ֲ������ͬѧ��:\n");

    for(i=0;i<SIZE;i++)/*ͳ��ƽ���ֲ���������*/

    {

       k=0;

        if(stu[i].average<60)

       {  

           m=i;/*�ҵ�ƽ���ֲ�����ѧ��������m�������±�*/

           OutputOneStudent(m);

           k++;/*kΪƽ���ֲ���������*/

       }

        printf("             ƽ���ֲ������ͬѧ��Ϣ�������\n");

        printf("��%d��\n",k);

        printf("  **********************************************************");

    }

    printf("ƽ����60~69�ֵ�ͬѧ��:\n");

    for(i=0;i<SIZE;i++)/*ͳ��ƽ����60~69������*/

    {

       k=0;

        if(stu[i].average>59&&stu[i].average<70)

       {     

           m=i;/*�ҵ�ƽ����69~69ѧ��������m�������±�*/

           OutputOneStudent(m);

            k++;/*kΪƽ����60~69������*/

       }

        printf("             ƽ����60~69�ֵ�ͬѧ��Ϣ�������\n");

        printf("��%d��\n",k);

        printf("  **********************************************************");

    }

    printf("ƽ����70~79�ֵ�ͬѧ��:\n");

    for(i=0;i<SIZE;i++)/*ͳ��ƽ����70~79������*/

    {

       k=0;

        if(stu[i].average>69&&stu[i].average<80)

       {     

           m=i;/*�ҵ�ƽ����70~79ѧ��������m�������±�*/

           OutputOneStudent(m);

           k++;/*kΪƽ����70~79������*/

       }

        printf("             ƽ����70~79�ֵ�ͬѧ��Ϣ�������\n");

        printf("��%d��\n",k);

        printf("  **********************************************************");

    }

    printf("ƽ����80~89�ֵ�ͬѧ��:\n");

    for(i=0;i<SIZE;i++)/*ͳ��ƽ����80~89������*/

    {

       k=0;

        if(stu[i].average>79&&stu[i].average<90)

       {     

           m=i;/*�ҵ�ƽ����80~89ѧ��������m�������±�*/

           OutputOneStudent(m);

           k++;/*kΪƽ����80~89������*/

       }

        printf("             ƽ����80~89�ֵ�ͬѧ��Ϣ�������\n");

        printf("��%d��\n",k);

        printf("  **********************************************************");

    }

    printf("ƽ����90~100�ֵ�ͬѧ��:\n");

    for(i=0;i<SIZE;i++)/*ͳ��ƽ����90~100������*/

    {

       k=0;

        if(stu[i].average>89&&stu[i].average<=100)

       {     

           m=i;/*�ҵ�ƽ����90~100ѧ��������m�������±�*/

           OutputOneStudent(m);

           k++;/*kΪƽ����90~100������*/

       }

        printf("             ƽ����90~100�ֵ�ͬѧ��Ϣ�������\n");

        printf("��%d��\n",k);

        printf("  **********************************************************");

    }

}

 

/*������߳ɼ�����****************************************************************************/

void search()

{

    int i=0,x,k=0;

    printf("********************�������ѡ��**********************\n");/*ѡ���ܲ˵�*/

    printf("          ���Ҹ����ɼ����ѧ���밴:1\n");

    printf("          ����Ӣ��ɼ����ѧ���밴:2\n");           

    printf("          ����C���Գɼ����ѧ���밴:3\n");

    scanf("%d",&x);/*�û�ѡ�����*/                        

    if(x==1)

    {

        for(i=0;i<SIZE;i++)/*���Ҹ����ɼ����ѧ��*/                   

       {   if(stu[i].score[0]>stu[k].score[0])

              i=k;

       }

       printf("�����ɼ����ѧ����Ϣ����:\n");

       OutputOneStudent(k);

       printf("                       �������\n");

        printf("  **********************************************************");

    }

    if(x==2)

    {

        for(i=0;i<SIZE;i++)/*����Ӣ��ɼ����ѧ��*/

       {   if(stu[i].score[1]>stu[k].score[1])

              i=k;

       }

       printf("Ӣ��ɼ����ѧ����Ϣ����:\n");

       OutputOneStudent(k);

       printf("                       �������\n");

        printf("  **********************************************************");

    }

    if(x==3)

    {

        for(i=0;i<SIZE;i++)/*����C���Գɼ����ѧ��*/

       {   if(stu[i].score[2]>stu[k].score[2])

              i=k;

       }

       printf("C���Գɼ����ѧ����Ϣ����:\n");

       OutputOneStudent(k);

       printf("                       �������\n");

        printf("  **********************************************************");

    }

}

 

/*ͳ�Ʋ������ʲ���*****************************************************************************/

void tongji2()

{

    int x,i,k;

    printf("********************����ͳ��ѡ��**********************\n"); /*ѡ���ܲ˵�*/

    printf("ͳ�Ƹ����ɼ����������밴:1\n");

    printf("ͳ��Ӣ��ɼ����������밴:2\n");           

    printf("ͳ��C���Գɼ����������밴:3\n");

    scanf("%d",&x);/*�û�ѡ����� */                        

    if(x==1)

    {

        for(i=0;i<SIZE;i++)/*ͳ�Ƹ����ɼ���������*/

       {

           k=0;

           if(stu[i].score[0]<60)

                k++;/*kΪ�����ɼ�����������*/

        printf("��%d�˸���δ����\n",k);

        printf("��������Ϊ%f\n",k/SIZE);

        printf("  **********************************************************");

       }

    }

    if(x==2)

    {

        for(i=0;i<SIZE;i++)/*ͳ��Ӣ��ɼ���������*/

       {

           k=0;

           if(stu[i].score[1]<60)

                 k++;/*kΪӢ��ɼ�����������*/

        printf("��%d��Ӣ�ﲻ����\n",k);

        printf("��������Ϊ%f\n",k/SIZE);

        printf("  **********************************************************");

       }

    }

    if(x==3)

    {

        for(i=0;i<SIZE;i++)/*ͳ��C���Գɼ���������*/

       {

           k=0;

           if(stu[i].score[2]<60)

                k++;/*kΪC���Գɼ�����������*/

        printf("��%d��C���Բ�����\n",k);

        printf("��������Ϊ%f\n",k/SIZE);

        printf("  **********************************************************");

       }

    }

}
