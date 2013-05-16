char** String_parser (char* string)
{
	char** parts=(char**) malloc (100*sizeof(char**));//этот массив я заполню распарсереной строкой
	if (parts==NULL)
	{
		printf ("error in malloc");
		return 0;
	}
	int i;//основной счетчик
	for (i=0;i<100;++i)
	{
		parts[i]=(char*) malloc (5*sizeof(char*));
		if (parts[i]==NULL)
		{
			printf ("error in malloc");
			return 0;
		}
	}
	int ii;
	int j=0;//номер буквы в текущем слове
	int k=0;//номер слова которое мы сейчас заполняем
	int s=100;//количество слов, есди что, увеличиваем его reallocом
	int p=100;//размер слова, если что увеличиваем его reallocом
	for (i=0;i<strlen(string)+1;++i)
	{	
		//printf ("strlen=%d\n",strlen(string));
		//printf ("i=%d\n",i);
		if (string[i]!=' ' && string[i]!='\n')
		{
			if (j<p)
			{
				//printf ("next i=%d\n",i);
				//printf ("k=%d   j=%d\n",k,j);
				parts[k][j]=string[i];
				//printf ("%c\n",parts[k][j]);
			}
			else
			{
				p=p*2;
				realloc(parts[k],p);
				parts[k][j]=string[i];
			}
			++j;
		}
		else
			if (string[i]==' ')
			{	
				//printf("%s\n",parts[k]);
				realloc(parts[k],j+1);
				if (parts[k]==NULL)
				{
					printf("error in realloc\n");
					return 0;
				}
				parts[k][j]='\0';
				j=0;
				k=k+1;
				if (k==s)
				{
					//printf("reallocation\n");
					s=s*2;
					realloc(parts,s);
					{
						for (ii=k;ii<s;++ii)
						{
							parts[ii]=(char*) malloc (100*sizeof(char*));
						}
					}
				//	printf("s=%d\n",s);
				//	parts[8]="terffdjhgfjd";
				//	printf ("%s\n",parts[8]);
				}
				p=100;
			}
	}
	realloc(parts,k+1);
	sizeOfArrayOfParameters=k+1;
	parts[k+1]=NULL;
	if (parts==NULL)
	{
		printf ("error in realloc");
		return 0;
	}
	return parts;
}
