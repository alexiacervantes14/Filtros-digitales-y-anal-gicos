float vec[7]={0.0,0.0,0.0,0.0,0.0,0.0,0.0}, copia[7]={0.0,0.0,0.0,0.0,0.0,0.0,0.0};
int i=0, j=0, ln=7;
float aux,c=0, r, temp;

void setup() 
{
   pinMode(A0, INPUT);
   Serial.begin(9600);
}

void loop() 
{
    c=analogRead(A0);
    c=c*(5.0/1023.0);
    temp=c/0.01;
  //Reacomodo
  for(i=6;i>=1;i--){
    vec[i]=vec[i-1];
  }
    vec[0]=temp;
    
 for(i=6;i>=0;i--){
    copia[i]=vec[i];
  }

    for(i=0; i<ln; i++)
    {
      for(j=0; j<(ln-1); j++)
      { 
        if(copia[j]>copia[j+1])
        {
          aux=copia[j+1];
          copia[j+1]=copia[j];
          copia[j]=aux;
        }
      }
    }
    
    r=copia[3];
    //Serial.println(temp);
    Serial.println(r);
    delay(10);
}
