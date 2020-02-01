    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
     
    int main()
    {
    	FILE* fa, *fb;
     
    	int ca,cb;
     
    	char key[10][10] = {"for","while","if","return","int","float","include", "long"};
     
    	fa = fopen("temp.c","r");
     	fb = fopen("temp_out_p3.txt", "w");

    	int line = 1;
    	int column = 1;
    	char temp[50];
    	for(int i = 0; i<30; ++i)
    		temp[i] = '\0';
    	int count = 0;
    	ca = getc(fa);

    	while(ca != EOF)
    	{
    		if(ca == '\n')
    		{
    			line++;
    			column = 1;
    			if(ca == EOF)
    				break;
    			ca = getc(fa);
    		}
    		else
    		{
    			if(ca >= 'a' && ca <= 'z')
    			{
    				temp[count++] = ca;
    			}
    			else
    				column++;
     
    			ca = getc(fa);
    			while(ca >= 'a' && ca <= 'z')
    			{
    				temp[count++] = ca;
    				ca = getc(fa);
    			}
     
    			//checking key array
    			//puts(temp);
    			if(count > 0)
    			{
    				for(int i = 0; i<8; ++i)
    					if(strncmp(temp,key[i],count) == 0)
    					{
    						fprintf(fb, "\nLine : %d Column : %d\t",line,column);
    						for (int j = 0;j<strlen(temp);j++){
    							fprintf(fb, "%c",temp[j]^32);
    						}
    						fprintf(fb, "\n");
    						break;
    					}
    				column += count;
    			}
     
    			if(ca == EOF)
    				break;
    		}
     
    		if(ca == EOF)
    				break;
     
    		count = 0;
    		for(int i = 0; i<30; ++i)
    			temp[i] = '\0';
    	}     
    	fclose(fa);
    	return 0;
    }