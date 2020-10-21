#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#define SIZE 3 /*定义常量SIZE便于以后的修改*/

struct student /*定义一个结构体数组存放学生的信息*/

{

    int number; /*学号*/

    char name[20];/*名字*/

    char xueyuan[20];/*学院*/

    int cla;/*班级*/

    int score[3];/*分数*/

    int sum;/*总分*/

    int average;/*平均分*/

}stu[SIZE];

 

void menu();/*调用菜单函数*/

void write();/*读入信息*/

void save(int x);/*保存stud.dat文件函数*/

void SaveOneStudent(int i);/*保存一个学生信息*/

void SaveAllStudent(int n);/*保存全部学生信息*/

void inturn (struct student c[]);/*用于对学生的信息按学号排序的函数*/

void save2();/*将排序后的信息存入student.dat文件中*/

int AddStudent(int n);/*增加学生信息*/

void InputOnestudent(int i);/*输入一个同学信息*/

int DelStudent(int n);/*删除学生信息*/

void ModifyStudent(int n);/*修改学生信息*/

void OutputOneStudent(int i);/*查询一个学生信息*/

void SearchMenu(int n);/*查询学生信息操作*/

void SearchNumber(int n);/*按学号查询学生信息*/

void SearchName(int n);/*按姓名查询学生信息*/

void SearchXueyuan(int n);/*按所在学院查询学生信息*/

void SearchCla(int n);/*按所在班级查询学生信息*/

void tongji();/*学生信息统计操作*/

void tongji2();/*统计不及格率操作*/

void zfsc();/*总分排序操作*/

void avecz();/*按平均分统计人数操作*/

void avecz();/*按平均分统计人数操作*/

void search();/*查找最高成绩操作*/

void tongji2();/*统计不及格率操作*/

void read();/*读取student.dat文件文件中学生的信息*/

 

/*主函数************************************************************************************/

int main(void)

{

    int n=SIZE;

    int choice;/*用户选择变量*/

    printf("*******************************************************************************\n");

    printf("*                                                                             *\n");

    printf("*          Hwadee            &学生成绩文件管理&          Hwadee               *\n");

    printf("*                                                                             *\n");

    printf("*******************************************************************************\n\n\n");

    printf("******************************●●欢迎使用●●*********************************");

    while (1)

    {

         menu();/*调用菜单函数形成操作界面*/

         printf("请选择:");

         scanf("%d", &choice);

         if ( choice==0 )

         {

              printf("\t\t\t\t谢谢使用!!!");

              break;

          }

       switch(choice) /*多重选择实现功能不同的功能*/

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

              printf("\n谢谢使用!再见!\n");

           default:

              printf("\n按键错误!请重新选择!\n");

       }/*结束switch*/

    }/*结束while*/

}



/*菜单函数*************************************************************************************/

void menu()

{

    printf("************请输入所需操作***********\n");/*选择功能菜单*/

    printf("*************************************\n");

    printf("1.学生成绩写入及排序\n");

    printf("2.增加学生信息\n");

    printf("3.删除学生信息\n");

    printf("4.修改学生信息\n");                             

    printf("5.查询学生信息\n");

    printf("6.学生成绩统计操作\n");

    printf("0.退出系统\n");

    printf("**************************************\n");

}

 

/*写入函数*************************************************************************************/

void write()

{

    int i;/*计数变量*/

    for(i=0;i<SIZE;i++)

    {

        printf("学号:");

        scanf("%d",&stu[i].number);

        printf("姓名:");

        scanf("%s",&stu[i].number);

        printf("学院:");

        scanf("%s",&stu[i].xueyuan);

        printf("班级:");

        scanf("%d",&stu[i].cla);

        printf("高数:");

        scanf("%d",&stu[i].score[0]);

        printf("英语:");

        scanf("%d",&stu[i].score[1]);

        printf("C语言:");

        scanf("%d",&stu[i].score[2]);

        stu[i].sum=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]);/*计算总成绩*/

        printf("总成绩:%d",stu[i].sum);

        stu[i].average=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;/*计算平均成绩*/

        printf("平均成绩:%d\n",stu[i].average);

    }

}

 

/*排序函数**************************************************************************************/

void inturn(struct student m[])

{

    int i,j;/*计数变量*/

    struct student temp;/*中间变量 类型为结构体*/

    for(i=0;i<SIZE-1;i++) /*运用冒泡排序对结构体数组进行排序*/

    for (j=i+1;j<SIZE-i-1;j++)

    {

       if(m[i].number>m[j].number)

       {

           temp=m[i];

           m[i]=m[j];

           m[j]=temp;

       }

    }

    printf("\n排序后的学生信息:\n\n");

    for (i=0;i<SIZE;i++)

    {

        printf("学号%d\t姓名%s\t学院%s\t班级%d\t高数%d\t英语%d\tC语言%d\t总成绩%d\t平均成绩%d\n\n",i+1,stu[i].number,stu[i].name,stu[i].xueyuan,stu[i].cla,stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);

    }/*输出排序后的学生信息*/ 

}

/*写入文件*************************************************************************************/

void save(int x)

{

    FILE *fp;/*定义文件指针用于向文件读入数据*/

    int i;

    if((fp=fopen("student.dat","rb+"))==NULL)/*以二进制读，写方式打开文件*/

    {

        printf("cannot open file\n");

       exit(1);

    }

    for(i=0;i<SIZE;i++)

        if(fwrite(&stu[i],sizeof(struct student),1,fp)!=1)

            printf("file write error\n");

    fclose(fp);

    printf("\n信息保存成功!恭喜!!\n");

}

 

/*保存一个学生信息******************************************************************************/

void SaveOneStudent(int i)

{

    FILE *fp;

    if((fp=fopen("student.dat","rb+"))==NULL)/*以二进制读，写方式打开文件*/

    {

        printf("文件打开失败!\n");

        exit(1);

    }

    fseek(fp,i,0);/*文件指针定位到第i个学生*/

    fwrite(&stu[i],sizeof(struct student),1,fp);/*将第i个学生信息写入文件*/

    fclose(fp);

}

 

/*保存全部学生信息******************************************************************************/

void SaveAllStudent(int n)/*保存全部学生信息*/

{

    FILE *fp;

    if((fp=fopen("student.dat","wb"))==NULL)/*以二进制写方式打开文件*/

    {

        printf("文件打开失败!\n");

        exit(1);

    }

    fwrite(stu,sizeof(struct student),n,fp);/*将数组stu中全部学生信息写入文件*/

    fclose(fp);

}

 

/*将排序后的学生信息读入到另外的文件中**********************************************************/

void save2()

{

    FILE *fp;

    int i;

    if((fp=fopen("stud.dat","rb+"))==NULL)/*以二进制读，写方式打开文件*/

    {

        printf("文件打开失败!\n");

        exit(1);

    }

    for (i=0;i<SIZE;i++)

        if (fwrite(&stu[i],sizeof(struct student),1,fp)!=1)

        printf("file write error\n");

    fclose(fp);/*读取完毕关闭文件*/

}

 

/*增加学生信息*********************************************************************************/

int AddStudent(int n)

{

    char c='y';

    FILE *fp;

    if((fp=fopen("student.dat","ab"))==NULL)/*以二进制追加方式打开文件*/

    {

        printf("文件打开失败!\n");

        exit(1);

    }

    while(c=='y')

    {

        printf("\n请输入要增加的同学的信息:");

        InputOnestudent(n);/*调用函数输入第n个学生信息*/

       fwrite(&stu[n],sizeof(struct student),1,fp);/*将第n个学生信息保存至文件*/

       n++;/*学生数量增加1*/

        printf("\n继续输入其他同学信息吗?\n");

        printf("确定进行删除请按y；不进行删除请按n\n");

       c=getchar();

        getchar();

    }/*结束while*/

    printf("\n按任意键继续!\n");

    getchar();

    fclose(fp);

    return(n);

}

 

/*输入一个同学信息*****************************************************************************/

void InputOnestudent(int i)

{

    printf("学号\t姓名\t学院\t班级\t高数\t英语\tC语言\n");

    scanf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t\n",&stu[i].number,stu[i].name,stu[i].xueyuan,&stu[i].cla,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);      

    stu[i].sum=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2]);/*计算总成绩*/      

    stu[i].average=(stu[i].score[0]+stu[i].score[1]+stu[i].score[2])/3;/*计算平均成绩*/

}

 

/*删除学生信息*********************************************************************************/

int DelStudent(int n)

{

    int i,k=-1,x;

    char c1='y',c2;

    while(c1=='y')

    {

       c2='n';

        printf("\n请输入要删除的同学的学号:");

        scanf("%d",&x);

        for(i=0;i<n;i++)

           if(x==stu[i].number)

           {

               k=i;/*找到要删除的同学学号，并用k记下其下标*/

               break;

           }

        if(k<0)/*k<0表示在数组中没有找到输入学号对应的学生*/

            printf("\n输入学号有误，请重新输入!");

        else

       {

            printf("\n该同学信息如下:\n");

            InputOnestudent(k);

            printf("\n确定删除?\n");

            printf("确定进行删除请按y；不进行删除请按n\n");

           c2=getchar();

           getchar();

           if(c2=='y')/*c2为y,表示确定进行删除操作*/

           {

               for(i=k;i<n;i++)

                  stu[i]=stu[i+1];/*删除第k个学生信息*/

               n--;/*学生人数减1*/

               printf("删除成功!恭喜!!\n");

           }

           else

               printf("\n取消删除!\n");

            printf("\n继续删除操作吗?");

            printf("\n继续删除请按y；不进行删除请按n\n");

           c1=getchar();

           getchar();

       }

    }/*结束while*/

    save(n);

    printf("\n按任意键继续!\n");

    getchar();

    return(n);

}

 

/*修改学生信息********************************************************************************/

void ModifyStudent(int n)

{

    struct student temp;

    int k=-1,x,i;

    char c1='y',c2;

    while(c1=='y')

    {

       c2='y';

        printf("\n请输入要修改的同学的学号:");

        scanf("%d",&x);

        for(i=0;i<n;i++)

           if(x==stu[i].number)

           {

               k=i;/*找到要修改的同学学号，并用k记下其下标*/

               break;

           }

        if(k<0)/*k<0表示在数组中没有找到输入学号对应的学生*/

            printf("\n输入学号有误，请重新输入!");

        else

       {

            printf("请输入要修改学生修改后的的信息\n");

            printf("学号\t姓名\t学院\t班级\t高数\t英语\tC语言\t\n");

            scanf("%d\t%s\t%s\t%d\t%d\t%d\t%d\t\n",&temp.number,stu[i].name,temp.xueyuan,&temp.cla,&temp.score[0],&temp.score[1],&temp.score[2]);      

           temp.sum=(temp.score[0]+temp.score[1]+temp.score[2]);/*计算总成绩*/      

           temp.average=(temp.score[0]+temp.score[1]+temp.score[2])/3;/*计算平均成绩*/

            stu[k]=temp;/*修改该学生信息*/

            printf("\n修改成功!恭喜!!\n");

           break;

       }

        SaveAllStudent(k);/*保存修改后的学生信息*/

        printf("\n继续修改操作吗?");

        printf("\n继续修改请按y；不进行修改请按n\n");

       c1=getchar();

        getchar();

    }/*结束while*/

    printf("\n按任意键继续!\n");

    getchar();

}

 

/*查询一个学生信息**********************************************************************************/

void OutputOneStudent(int i)

{

    printf("学号:%d  姓名:%s  学院:%s  班级:%d\n",stu[i].number,stu[i].name,stu[i].xueyuan,stu[i].cla);

    printf("高数:%d  英语:%d  C语言:%d  总分:%d  平均分:%d\n",stu[i].score[0],stu[i].score[1],stu[i].score[2],stu[i].sum,stu[i].average);

}

 

/*查询学生信息操作*********************************************************************************/

void SearchMenu(int n)

{

    int selet;

    while(1)

    {

        printf("**********************************************************\n");

        printf("******************** 欢迎进入查询系统  *******************\n");    

        printf("**********************************************************\n");

        printf("\n");

        printf("*********************  请输入所需操作  *******************\n");/*选择功能菜单*/

        printf("**********************************************************\n");

        printf("1.按学号查询\n");

        printf("2.按姓名查询\n");

        printf("3.按学院查询\n"); 

        printf("4.按班级查询\n");

        printf("0.返回主菜单\n");     

        printf("**********************************************************\n");

        printf("请输入操作选项:");

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

              printf("输入错误!请重新输入!\n");

       }

    }/*结束while*/

}

 

/*按姓名查询学生信息*******************************************************************************/

void SearchName(int n)

{

    int i,j,k;

    char xname[20],c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n请输入学生姓名:");

       gets(xname);

       for(i=0,j=1;i<n;i++)/*精确查询*/

           if(strcmp(stu[i].name,xname)==0)

           {

               k=i;/*找到要查询的同学姓名,并用k记下其下标*/

               printf("学生%d的信息:\n",j++);

                OutputOneStudent(k);

                printf("\n按任意键继续!\n");

                getchar();

           }

       if(k==-1)/*k表示没有精确查询结果*/

       {

           printf("\n模糊查询结果如下:\n");

           for(i=0,j=1;i<n;i++)

              if(strstr(stu[i].name,xname)!=NULL)/*模糊查询*/

              {

                  k=1;

                   printf("学生%d的信息:\n",j++);

                    OutputOneStudent(k);

                    printf("\n按任意键继续!\n");

                    getchar();

              }

           if(j==1)

                printf("\n抱歉!没有该学生信息!\n");

       }

       printf("继续查询其他学生信息吗?");

        printf("\n继续修改请按y；不进行修改请按n\n");

       c=getchar();

        getchar();

    }/*结束while*/

    printf("\n按任意键继续!\n");

    getchar();

}

 

/*按学号查询学生信息*******************************************************************************/

void SearchNumber(int n)

{

    int i,j,k,x;

    char c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n请输入学生学号:");

       scanf("%d",&x);

       for(i=0,j=1;i<n;i++)

           if(stu[i].number==x)

           {

               k=i;/*找到要查询的同学学号,并用k记下其下标*/

               printf("学生%d的信息:\n",j++);

                OutputOneStudent(k);

                printf("\n按任意键继续!\n");

                getchar();

           }

       printf("继续查询其他学生信息吗?");

        printf("\n继续修改请按y；不进行修改请按n\n");

       c=getchar();

        getchar();

    }/*结束while*/

    printf("\n按任意键继续!\n");

    getchar();

}

 

/*按所在学院查询学生信息***************************************************************************/

void SearchXueyuan(int n)

{

    int i,j,k;

    char xxueyuan[20],c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n请输入学生所在学院:");

       gets(xxueyuan);

       for(i=0,j=1;i<n;i++)

           if(strcmp(stu[i].xueyuan,xxueyuan)==0)

           {

               k=i;/*找到要查询的同学所在学院,并用k记下其下标*/

               printf("学生%d的信息:\n",j++);

                OutputOneStudent(k);

                printf("\n按任意键继续!\n");

                getchar();

           }

       printf("继续查询其他学生信息吗?");

        printf("\n继续修改请按y；不进行修改请按n\n");

       c=getchar();

        getchar();

    }/*结束while*/

    printf("\n按任意键继续!\n");

    getchar();

}

 

/*按所在班级查询学生信息***************************************************************************/

void SearchCla(int n)

{         

    int i,j,k,x;

    char c='y';

    while(c=='y')

    {

       k=-1;

       printf("\n请输入学生所在班级:");

       scanf("%d",&x);

       for(i=0,j=1;i<n;i++)

           if(stu[i].cla==x)

           {

               k=i;/*找到要查询的同学所在班级,并用k记下其下标*/

               printf("学生%d的信息:\n",j++);

                OutputOneStudent(k);

                printf("\n按任意键继续!\n");

                getchar();

           }

       printf("继续查询其他学生信息吗?");

        printf("\n继续修改请按y；不进行修改请按n\n");

       c=getchar();

        getchar();

    }/*结束while*/

    printf("\n按任意键继续!\n");

    getchar();

}

 

/*学生信息统计操作*********************************************************************************/

void tongji()

{  

    int x;

    printf("**********************************************************\n");

    printf("******************** 欢迎进入统计系统  *****************++\n");       

    printf("**********************************************************\n");

    printf("\n");

    printf("************请输入所需操作***********\n");/*选择功能菜单*/

    printf("*************************************\n");

    printf("1.按总分排序操作\n");

    printf("2.按平均分统计人数操作\n");                         

    printf("3.按查找最高成绩操作\n");

    printf("4.按统计部及格率操作\n");                             

    printf("0.返回主菜单\n");

    printf("**************************************\n");

    printf("请输入操作选项:");

    scanf("%d",&x);/*用户选择变量*/

    while(x>0&&x<6)

    {

        switch(x)

       {

           case 1:

                 zfsc();break;/*选择按总分排序操作*/        

             case 2:

                  avecz();break;/*选择按平均分统计人数操作*/

             case 3:

                  search();break;/*选择按查找最高成绩操作*/

             case 4:

                  tongji();break;/*选择按统计部及格率操作*/

             case 0:

                printf("谢谢使用!再见!\n");

               return;/*选择退出操作*/

             default:

                printf("输入错误!请重新输入\n");/*提示错误信息*/

       }

    }

}

 

/*总分排序操作*************************************************************************************/

void zfsc()

{

    FILE *wj,*fp;

    int i,j;

    struct student temp;

    if((fp=fopen("student.dat","wb"))==NULL)

    {

        printf("文件打开失败!\n");

       exit(1);

    }

    for(i=0;i<SIZE-1;i++)

        for(j=0;j<SIZE-i-1;j++)

            if(stu[i].sum<stu[j].sum)/*冒泡法排序*/

            {

                temp=stu[j];

                stu[j]=stu[i];

                stu[i]=temp;

            }

    if((wj=fopen("student1.dat","wb+"))==NULL)

    {

        printf("文件打开失败!\n");

       exit(1);

    } 

    else

    {   

         for(i=0;i<SIZE;i++)

             fwrite(&stu[i],sizeof(struct student),1,wj);/*写入文件*/

    }

    fclose(fp);

    fclose(wj);

}

 

/*按平均分统计人数操作*****************************************************************************/

void avecz()

{

    int i=0,k,m;

    printf("平均分不及格的同学有:\n");

    for(i=0;i<SIZE;i++)/*统计平均分不及格人数*/

    {

       k=0;

        if(stu[i].average<60)

       {  

           m=i;/*找到平均分不及格学生，并用m记下其下标*/

           OutputOneStudent(m);

           k++;/*k为平均分不及格人数*/

       }

        printf("             平均分不及格的同学信息输出结束\n");

        printf("共%d人\n",k);

        printf("  **********************************************************");

    }

    printf("平均分60~69分的同学有:\n");

    for(i=0;i<SIZE;i++)/*统计平均分60~69分人数*/

    {

       k=0;

        if(stu[i].average>59&&stu[i].average<70)

       {     

           m=i;/*找到平均分69~69学生，并用m记下其下标*/

           OutputOneStudent(m);

            k++;/*k为平均分60~69分人数*/

       }

        printf("             平均分60~69分的同学信息输出结束\n");

        printf("共%d人\n",k);

        printf("  **********************************************************");

    }

    printf("平均分70~79分的同学有:\n");

    for(i=0;i<SIZE;i++)/*统计平均分70~79分人数*/

    {

       k=0;

        if(stu[i].average>69&&stu[i].average<80)

       {     

           m=i;/*找到平均分70~79学生，并用m记下其下标*/

           OutputOneStudent(m);

           k++;/*k为平均分70~79分人数*/

       }

        printf("             平均分70~79分的同学信息输出结束\n");

        printf("共%d人\n",k);

        printf("  **********************************************************");

    }

    printf("平均分80~89分的同学有:\n");

    for(i=0;i<SIZE;i++)/*统计平均分80~89分人数*/

    {

       k=0;

        if(stu[i].average>79&&stu[i].average<90)

       {     

           m=i;/*找到平均分80~89学生，并用m记下其下标*/

           OutputOneStudent(m);

           k++;/*k为平均分80~89分人数*/

       }

        printf("             平均分80~89分的同学信息输出结束\n");

        printf("共%d人\n",k);

        printf("  **********************************************************");

    }

    printf("平均分90~100分的同学有:\n");

    for(i=0;i<SIZE;i++)/*统计平均分90~100分人数*/

    {

       k=0;

        if(stu[i].average>89&&stu[i].average<=100)

       {     

           m=i;/*找到平均分90~100学生，并用m记下其下标*/

           OutputOneStudent(m);

           k++;/*k为平均分90~100分人数*/

       }

        printf("             平均分90~100分的同学信息输出结束\n");

        printf("共%d人\n",k);

        printf("  **********************************************************");

    }

}

 

/*查找最高成绩操作****************************************************************************/

void search()

{

    int i=0,x,k=0;

    printf("********************输入查找选项**********************\n");/*选择功能菜单*/

    printf("          查找高数成绩最高学生请按:1\n");

    printf("          查找英语成绩最高学生请按:2\n");           

    printf("          查找C语言成绩最高学生请按:3\n");

    scanf("%d",&x);/*用户选择变量*/                        

    if(x==1)

    {

        for(i=0;i<SIZE;i++)/*查找高数成绩最高学生*/                   

       {   if(stu[i].score[0]>stu[k].score[0])

              i=k;

       }

       printf("高数成绩最高学生信息如下:\n");

       OutputOneStudent(k);

       printf("                       输出结束\n");

        printf("  **********************************************************");

    }

    if(x==2)

    {

        for(i=0;i<SIZE;i++)/*查找英语成绩最高学生*/

       {   if(stu[i].score[1]>stu[k].score[1])

              i=k;

       }

       printf("英语成绩最高学生信息如下:\n");

       OutputOneStudent(k);

       printf("                       输出结束\n");

        printf("  **********************************************************");

    }

    if(x==3)

    {

        for(i=0;i<SIZE;i++)/*查找C语言成绩最高学生*/

       {   if(stu[i].score[2]>stu[k].score[2])

              i=k;

       }

       printf("C语言成绩最高学生信息如下:\n");

       OutputOneStudent(k);

       printf("                       输出结束\n");

        printf("  **********************************************************");

    }

}

 

/*统计不及格率操作*****************************************************************************/

void tongji2()

{

    int x,i,k;

    printf("********************输入统计选项**********************\n"); /*选择功能菜单*/

    printf("统计高数成绩不及格率请按:1\n");

    printf("统计英语成绩不及格率请按:2\n");           

    printf("统计C语言成绩不及格率请按:3\n");

    scanf("%d",&x);/*用户选择变量 */                        

    if(x==1)

    {

        for(i=0;i<SIZE;i++)/*统计高数成绩不及格率*/

       {

           k=0;

           if(stu[i].score[0]<60)

                k++;/*k为高数成绩不及格人数*/

        printf("共%d人高数未及格\n",k);

        printf("不及格率为%f\n",k/SIZE);

        printf("  **********************************************************");

       }

    }

    if(x==2)

    {

        for(i=0;i<SIZE;i++)/*统计英语成绩不及格率*/

       {

           k=0;

           if(stu[i].score[1]<60)

                 k++;/*k为英语成绩不及格人数*/

        printf("共%d人英语不及格\n",k);

        printf("不及格率为%f\n",k/SIZE);

        printf("  **********************************************************");

       }

    }

    if(x==3)

    {

        for(i=0;i<SIZE;i++)/*统计C语言成绩不及格率*/

       {

           k=0;

           if(stu[i].score[2]<60)

                k++;/*k为C语言成绩不及格人数*/

        printf("共%d人C语言不及格\n",k);

        printf("不及格率为%f\n",k/SIZE);

        printf("  **********************************************************");

       }

    }

}
