#include <stdio.h>
#include <string.h>
#include <ctype.h>

void place(int[][16],int n);                                            /*関数のプロトタイプ宣言*/
void disp(int[][16],int n);


/********************************/
/*メイン関数
/*   作業配列の初期化を行う
/*
/*パラメータ：なし
/*リターン  ：0：OK 
/*******************************/

int main( void )
{
    int work[16][16]={0};
    char dmy[80];
    int i,j,n;
    while(1){
        printf("3以上15以下の奇数を入力してください：");
        if(scanf("%d",&n)!=1){                                        /*ニューメリックチェック*/
            gets(dmy);
            printf("数字を入力してください。\n");
            continue;
        }
        if(n%2==0){
            printf("奇数を入力してください。\n");
                
        }else{
            if(n<3){
                printf("3以上15以下の奇数を入力してください。\n");
            }else{
                    break;
            }
        }
    }
    for(j=0;j<=n+1;j++){                                                /*行の初期化*/
        for(i=0;i<=n+1;i++){                                            /*列の初期化*/
            if(i==0||i==n+1||j==0||j==n+1){                             /*作業領域かどうか検知用数字*/
                work[j][i]=n*n+1;
            }else{
                work[j][i]=0;
            }
            
        }
    }
    place(work,n);
    disp(work,n);


    return 0;
}


/************************************/
/*数字の場所決めと配置を行う
/*
/*パラメータ：int work[][16] [in/out]
/*            int n[in]
/*リターン  ：なし
/***********************************/
void place(int work[][16],int n)
{
    int i,j,num;
    num=1;
    while(num<n*n+1){
        if(num==1){                                                      /*i,jの初期値*/
            i=n/2+1;
            j=n/2+2;
        }
        while(1){
            if(i>n){                                                     /*右にはみだした時*/
                i=1;
            }else if(1>i){                                               /*左にはみだした時*/
                i=n;
            }
            if(j>n){                                                     /*下にはみだした時*/
                j=1;
            }

            if(work[j][i]==0){                                           /*数字が入っていない*/
                break;
            }else{                                                       /*すでに入っている*/
                i--;
                j++;
            }

            
        }

        work[j++][i++]=num++;

    }
    

}

/************************************/
/*魔法陣の表示
/*
/*パラメータ：int work[][16][in]
/*            int n[in]
/*リターン  ：なし
/***********************************/

void disp(int work[][16],int n)
{
    int i,j;
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            printf("%d\t",work[j][i]);
        }
        printf("\n");
    }
    
}

