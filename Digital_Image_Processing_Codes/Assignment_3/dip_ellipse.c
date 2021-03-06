/*
	Author: Hardik Udeshi
	Description: Take the boat image as your input. Now, draw and fill an ellipse on that image,
				keeping the centre of the image as the centre for the ellipse that you draw.
*/



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <fcntl.h>

void main()
{
	//input variables
	char output_file[100],input_file[100];
	unsigned char *image;
	int pix,npix,scan,nscan, *fp1,*fp2,midx,midy;

	//npix and nscan
	printf("Give npix nscan \n");
	scanf("%d %d",&npix,&nscan);

	//input and output image array
	image = (unsigned char *)calloc(npix,sizeof(unsigned char));

	//input file
	printf("Give me input file \n");
	scanf("%s",input_file);

	//output file
	printf("Give me output file \n");
	scanf("%s",output_file);
	printf("Output file is %s\n",output_file);
	float x,y,a,b;

	//Major and minor axis
	printf("Give a: \n");
	scanf("%f",&a);
	printf("Give b: \n");
	scanf("%f",&b);


	//centre of the image
	midx = (npix+1)/2;
	midy = (nscan+1)/2;

	//opening the input file
	fp1=open(input_file,O_RDONLY);

	if(fp1<0)
	{
		printf("Error in Opening the File.\n");
		exit(1);
	}

	//creating the output file
	fp2 = creat(output_file,0666);

	if(fp2<0)
	{
		printf("Error in creating file\n");
		exit(1);
	}

	//for loop for number of rows
	for(scan=0;scan<nscan;scan++)
	{
		//reading the file
		read(fp1,&image[0],npix*sizeof(unsigned char));
		
		//for loop for number of cols
		for(pix=0;pix<npix;pix++)
		{
			//taking the x and y co-ordinates
			x = pix - midx;
			y = midy - scan;

			//checking the equation of an ellipse
			if(((x*x/(a*a) + y*y/(b*b)) -1<=(float)(1)))
			{
				image[pix] = 0;
			}
		}

		//writing into the file
		write(fp2,&image[0],npix*sizeof(unsigned char));
	}

	//closing the files
	close(fp1);
	close(fp2);


}
