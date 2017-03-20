int PesquisaBinaria ( int k[], int who , int N)
{
 int inf,sup,meio;
 inf=0;
 sup=N-1;
 while (inf<=sup)
 {
      meio=(inf+sup)/2;
      if (who==k[meio])
           return meio;
      else if (who<k[meio])
           sup=meio-1;
      else
           inf=meio+1;
 }
 return -1;  
}