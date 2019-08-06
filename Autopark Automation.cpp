/*
	VELÝCAN EVLÝ
	16010011030	
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
int sayac;
struct tarih 
{
	int gun;
	int ay;
	int yil;			
};
struct araba
{
	char plaka[20];
	char marka[20];
	char model[20];
	char renk[20];
	int yil;
};
typedef struct musteri
{
	char ad[20];
	char soyad[20];
	long int TC;
	long int telefon;
	struct musteri *ileri;
	struct araba arabalar;
	struct tarih giriscikis;

}musteriler;
musteriler *ilk=NULL,*son=NULL,*temp,*iter;


void kontrol();
musteriler *arabasil(musteriler *);
struct musteri *bilgial(struct musteri *);
void kaydet(struct musteri *);
void arabaekle();
void yaz(musteriler *);
void bilgiguncelle();
musteriler *ucrethesap(musteriler *);
struct musteri *dosyaac();
void gc(struct musteri *);

void menu()
{
	int secim;
	printf("\n\t\t  OTOPARK \n\t\t");
	
	printf("\n\t\t1-Araba Ekle\n\t\t2-Araba Sil\n\t\t3-Arac Bilgileri Guncelle\n\t\t4-Goruntule\n\t\t5-Arac Cikis\n\t\t6-Dosyaya Kaydet\n\t\t7-Dosya Ac\n\t\tSecim :"); scanf("%d",&secim);
	switch(secim)
	{
		case 1 : arabaekle(); menu(); break;
		case 2 : ilk=arabasil(ilk); menu(); break;
		case 3 : bilgiguncelle(); menu();break;
		case 4 : yaz(ilk); menu(); break;
		case 5 : ilk=ucrethesap(ilk);  menu(); break;
		case 6 : kaydet(ilk); menu(); break; 
		case 7 : ilk=dosyaac(); iter=ilk; menu(); break;
		default : printf("\n\t\tYanlis Giris !"); menu(); break;
	}
}

void arabaekle()
{
	temp=(musteriler *)malloc(sizeof(musteriler));
	temp->ileri=NULL;
	bilgial(temp);
	system("cls");
	printf("\n\t\tMusteri Basari ile Eklendi.");
	if(ilk==NULL)
	{
		ilk=temp;
		son=temp;
		son=ilk;
	}
	else
	{
		son->ileri=temp;
		son=son->ileri;
	}
	sayac++;
}
musteriler *arabasil(musteriler *ilk)
{
	system("cls");
	int secim;
	char silinecek[20];
	printf("\n\t\t1-Isme Gore\n\t\t2-Plakaya Gore\n\t\t3-Geri\n\t\tSecim :"); scanf("%d",&secim);
	
	switch(secim)
	{
		case 1 :	
		printf("\n\t\tMusterinin Adi  :"); scanf("%s",&silinecek);
	iter=ilk;
	if(ilk==NULL)
	{
		printf("\n\t\tListede Silinecek Musteri Yok");
		return 0;
	}
	
	if(strcmp(ilk->ad,silinecek)==0)
	{
		temp=ilk;
		ilk=ilk->ileri;
		free(temp);
		return ilk;
		sayac--;
	}
	ilk=iter;
		while(strcmp(iter->ileri->ad,silinecek)!=0 && iter->ileri!=NULL)
		{
			iter=iter->ileri;
		}
		if(iter->ileri==NULL)
		{
			printf("Silinecek Eleman Bulunamadi.");
		}
		temp=iter->ileri;
		iter->ileri=iter->ileri->ileri;
		free(temp);
		sayac--;
		printf("\n\t\tMusteri Basari Ile Silindi!");
		return ilk;
		 break;
		case 2 : 
				printf("\n\t\tAracin Plakasi  :"); scanf("%s",&silinecek);
	iter=ilk;
	if(ilk==NULL)
	{
		printf("\n\t\tListede Silinecek Musteri Yok");
		return 0;
	}
	
	if(strcmp(ilk->arabalar.plaka,silinecek)==0)
	{
		temp=ilk;
		ilk=ilk->ileri;
		free(temp);
		printf("\n\t\tMusteri Basari Ile Silindi!");
		sayac--;
		return ilk;
	}
	ilk=iter;
		while(strcmp(iter->ileri->arabalar.plaka,silinecek)!=0 && iter->ileri!=NULL)
		{
			iter=iter->ileri;
		}
		if(iter->ileri==NULL)
		{
			printf("\n\t\tSilinecek Eleman Bulunamadi.");
		}
		temp=iter->ileri;
		iter->ileri=iter->ileri->ileri;
		free(temp);
		printf("\n\t\tMusteri Basari Ile Silindi!");
		sayac--;
		return ilk;
		break;
		case 3 : system("cls"); menu(); break;
		default : printf("\n\t\tYanlis Giris !"); arabasil(ilk); break; 
		
	}
	
}
	
struct musteri *bilgial(struct musteri *x)
{
	time_t s;
	system("cls");
	printf("\n\t\tMusterinin ");
	printf("\n\t\tAdi :"); scanf("%s",&x->ad);
	printf("\n\t\tSoyadi :"); scanf("%s",&x->soyad);
	printf("\n\t\tTC :"); scanf("%ld",&x->TC);
	printf("\n\t\tTelefon : "); scanf("%ld",&x->telefon);
	printf("\n\t\tAracin");
	printf("\n\t\tPlakasi :"); scanf("%s",&x->arabalar.plaka);
	printf("\n\t\tMarkasi :"); scanf("%s",&x->arabalar.marka);
	printf("\n\t\tModeli :"); scanf("%s",&x->arabalar.model);
	printf("\n\t\tRengi :"); scanf("%s",&x->arabalar.renk);
	printf("\n\t\tYil :"); scanf("%d",&x->arabalar.yil);

	gc(x);

/*	printf("%d ",x->giriscikis.gun);
	printf("%d ",x->giriscikis.ay);
	printf("%d ",x->giriscikis.yil);*/
	return x;	
}
void yaz(musteriler *x)
{
	system("cls");
	int sayac;
	if(x==NULL)
	{
		system("cls");
		printf("\n\t\tListe Bos!\n");
		printf("\n\t\tOtoparktaki Bos Alan :%d",sayac);
		 menu();
	}
	
	while(x!=NULL)
	{
//		printf("\nAD\t SOYAD\t TC\t TEL\t MARKA\t MODEL\t RENLK\t YIL\t\n\n");
		printf("\n\t\t%s\t",x->ad);
		printf("%s\t",x->soyad);
		printf("%ld\t",x->TC);
		printf("%ld\t",x->telefon);
		printf("%s\t",x->arabalar.plaka);
		printf("%s\t",x->arabalar.marka);
		printf("%s\t",x->arabalar.model);
		printf("%s\t",x->arabalar.renk);
		printf("%d\t",x->arabalar.yil);
		printf("%d\t",x->giriscikis.gun);
		printf("%d\t",x->giriscikis.ay);
		printf("%d\t",x->giriscikis.yil);
		x=x->ileri;
		sayac++;
	}
	printf("\n\t\tOtoparktaki Bos Alan :%d\n",100-sayac);

}
void bilgiguncelle()
{
		system("cls");
	char ad[20];
	printf("\n\t\tBilgileri Guncellenecek Musterinin Adi :"); scanf("%s",&ad);
	iter=ilk;
	if(iter==NULL)
	{
			system("cls");
		printf("\n\t\tMusteri Listesi Bos!");
	}

	while(iter!=NULL)
	{
		if(strcmp(ad,iter->ad)==0)
		{
			printf("Yeni Bilgilerinizi Giriniz\n");
			printf("\n\t\tAd :"); scanf("%s",&iter->ad);
			printf("\n\t\tSoyad :"); scanf("%s",&iter->soyad);
			printf("\n\t\tTC :"); scanf("%ld",&iter->TC);
			printf("\n\t\tTelefon :"); scanf("%ld",&iter->telefon);
			printf("\n\t\tPlaka :"); scanf("%s",&iter->arabalar.plaka);
			printf("\n\t\tMarka :"); scanf("%s",&iter->arabalar.marka);
			printf("\n\t\tModel :"); scanf("%s",&iter->arabalar.model);
			printf("\n\t\tRenk :"); scanf("%s",&iter->arabalar.renk);
			printf("\n\t\tYil :"); scanf("%d",&iter->arabalar.yil);
		}
		iter=iter->ileri;
	}
	printf("\n\t\tEleman Bulunamadi.");

}
struct musteri *dosyaac()
{
	musteriler *gecici;
	FILE *dosya1;
	dosya1=fopen("1630.txt","r");
	if(dosya1==NULL)
	{
		printf("\n\t\tDosya Bulunamadi.");
	}
	
  /* if(ilk==NULL)
   {
   	iter=ilk=(musteri *)malloc(sizeof(musteri)); 
   	iter=ilk;
	} 
	else
	{	
		iter=(musteri *)malloc(sizeof(musteri));
		iter=iter->ileri;
	
	}*/
	iter=ilk=(musteriler *)malloc(sizeof(musteriler));
	while(!feof(dosya1))
	{
		fscanf(dosya1,"%s %s %ld %ld %s %s %s %s %d %d %d %d",&iter->ad,&iter->soyad,&iter->TC,&iter->telefon,&iter->arabalar.plaka,&iter->arabalar.marka,&iter->arabalar.model,&iter->arabalar.renk,&iter->arabalar.yil,&iter->giriscikis.gun,&iter->giriscikis.ay,&iter->giriscikis.yil);
		iter->ileri=(musteri *)malloc(sizeof(musteri));
		
//		printf("%s %s %ld %ld %s %s %s %s %d\n",iter->ad,iter->soyad,iter->TC,iter->telefon,iter->arabalar.plaka,iter->arabalar.marka,iter->arabalar.model,iter->arabalar.renk,iter->arabalar.yil);
		
		iter=iter->ileri;
	}
	iter->ileri=NULL;
		system("cls");
	printf("\n\t\tDosya Basari Ile Sisteme Yuklendi.");
		fclose(dosya1);
		return ilk;
}

void kaydet(struct musteri *x)
{
		if(x==NULL)
		{
			system("cls");
			printf("\n\t\tKaydedilecek Birsey Bulunamadi.");
			menu();
		}
		FILE *dosya;
		dosya=fopen("1630.txt","a+");
	if(dosya==NULL)
	{
		printf("\n\t\tDosya Bulunamadi.");
	}
		while(x!=NULL)
		{
			
			fprintf(dosya,"%s\t %s\t %ld\t %ld\t %s\t %s\t %s\t %s\t %d\t %d\t %d\t %d\t",x->ad,x->soyad,x->TC,x->telefon,x->arabalar.plaka,x->arabalar.marka,x->arabalar.model,x->arabalar.renk,x->arabalar.yil,x->giriscikis.gun,x->giriscikis.ay,x->giriscikis.yil);
			fprintf(dosya,"\n");
				x=x->ileri;
		}

		fclose(dosya);
		printf("\n\t\tDosya Basari ile kaydedildi!");
	
}
musteriler *ucrethesap(musteriler *x)
{
	time_t lt,giris; lt=time(NULL); 
	struct tm* local=localtime(&lt);
	char cikis[20];
	int g,g1,a,a1,y,y1;
	printf("\n\t\tCikis Yapan Aracin Plakasi :"); scanf("%s",&cikis);
	
	while(x->ileri!=NULL)
	{
		if(strcmp(x->arabalar.plaka,cikis)==0)
		{
			printf("\n\t\tArac Giris Tarihi : %d:%d:%d",x->giriscikis.gun,x->giriscikis.ay,x->giriscikis.yil);
			printf("\n\t\tCikis tarihi : %d:%d:%d",local->tm_mday,local->tm_mon,local->tm_year+1900);
			   g1=local->tm_mday;
			   a1=local->tm_mon+1;
			   y1=local->tm_year+1900;
			 if(x->giriscikis.gun>g1)
			 {
			 	g1=g1+30;
				a1=a1-1;	
			 } 
			 if(x->giriscikis.ay>a1)
			 {
			 	a1=a1+12;
			 	y1=y1-1;
			 }
		
			g=g1-x->giriscikis.gun; a=a1-x->giriscikis.ay; y=y1-x->giriscikis.yil;
				printf("\n\t\tAracin Otoparkta Kaldigi Sure: %d:%d:%d",g,a,y);
	
			if(y==0 && a==0)
			{
				printf("\n\t\tBorcunuz :%d TL",g*20);
			}
			if(y==0)
			{
				printf("\n\t\tBorcunuz :%d TL",a*90+g*15);
			}
			else
			{
				printf("\n\t\tBorcunuz :%d TL",y*200+a*60+g*10);
			}			
				
			if(strcmp(ilk->arabalar.plaka,cikis)==0)
			{
				temp=ilk;
				ilk=ilk->ileri;
				free(temp);
				return ilk;
			}
			
			ilk=iter;
			while(strcmp(iter->ileri->arabalar.plaka,cikis)!=0 && iter->ileri!=NULL)
			{
				iter=iter->ileri;
			}
				temp=iter->ileri;
				iter->ileri=iter->ileri->ileri;
				free(temp);
				printf("\n\t\tMusteri Basari Ile Cikis Yapti !");
				return ilk;
		}

		x=x->ileri;
	}

	printf("\n\t\tBu Plakaya Sahip Arac Bulunamadi.");
	
}
void gc(struct musteri *a)
{
	srand(time(NULL));
	int gun,ay,yil;
	gun=1+rand()%30;
	ay=1+rand()%12;
	yil=2000+rand()%19;
	
	a->giriscikis.gun=gun;
	a->giriscikis.ay=ay;
	a->giriscikis.yil=yil;
	
}
void kontrol()
{
	int giris=3,giris1=3;
	char kullanici[20]={"admin"},kadi[20],ksifre[20],sifre[20]={"12345"};
	system("cls");
	a:printf("\n\t\tKullanici Adi :"); scanf("%s",&kadi);
	while(giris>0)
	{
		if(strcmp(kadi,kullanici)==0)
	{
		while(giris1>0)
		{		
			system("cls");
			b: printf("\n\t\tSifre :"); scanf("%s",&ksifre);
			if(strcmp(sifre,ksifre)==0)
			{
				menu();
			}
			else
			{
				system("cls");
				printf("\n\t\tYanlis Sifre Girdiniz! Kalan Deneme Sayisi :%d",giris1); 	
				
				if(giris1==0) 
				{		
					printf("\n\t\t3 defa Yanlis Sifre Girisi Yaplidi .Lutfen Daha Sonra Tekrar Deneyiniz!!"); exit(0);
				}
				giris1--; 
				goto b;
			
			}
	
		}

	}

	else
	{
	 system("cls");	printf("\n\t\tYanlis Kullanici Adi Girdiniz! Kalan Deneme Sayisi :%d",giris); giris--; goto a;
	}
		
	
	}
		if(giris==0)
		printf("\n\t\t3 defa Yanlis Kullanici Adi Girisi Yaplidi .Lutfen Daha Sonra Tekrar Deneyiniz!!"); exit(0);
	
	system("cls");	
}
int main()
{	
	kontrol();
	menu();
}
