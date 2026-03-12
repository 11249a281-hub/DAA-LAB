#include<stdio.h>
struct  Item{
    int weight;
    int profit;
    float ratio;
    int value;
};
void sort(struct Item items[],int n)
{
    struct Item temp;
    for (int i = 0; i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
           if(items[j].ratio<items[j+1].ratio)
            {
                temp=items[j];
                items[j]=items[j+1];
            }
        }
   
    }

   
}
int main(){
    int n;
    float capacity;
    printf("enter the number of items:");
    scanf("%d", &n);
    struct Item itm[n] ;
      for (int  i=0;i<n;i++){
         printf("enter item %d weight  profit:",i+1);
         scanf("%d %d",&itm[i].weight,&itm[i].profit);
         itm[i].ratio=itm[i].profit/itm[i].weight;
     }
    printf("enter knapsack capacity:");
    scanf("%f",&capacity);
   
   
    sort(itm,n);
    float totalProfit=0.0;
    for(int i=0; i<n; i++)
    {
        if(capacity >=itm[i].weight)
        {
            totalProfit += itm[i].value;
            capacity -= itm[i].weight;
        }
        else
        {
            totalProfit += itm[i].ratio*capacity;
            break;
           
        }
    }
    printf("Maximum profit = %.2f\n",totalProfit);
    return 0;
}
