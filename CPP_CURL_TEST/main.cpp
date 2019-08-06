#include <iostream>
#include <cstdio>
#include  "include\curl\curl.h"
#include  "include\curl\easy.h"
using namespace std;

void pause()
{
    printf("Press Enter key to continue…");
    fgetc(stdin);
}
int main()
{
    CURL *curl;
    CURLcode res;
    struct  curl_slist  *headerlist = NULL;
    static  const char buf[] = "application/json; charset=UTF-8";
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if(curl)
    {
        headerlist = curl_slist_append(headerlist, buf);
        //curl_easy_setopt(curl, CURLOPT_URL, "https://www.mof.gov.tw");
        curl_easy_setopt(curl, CURLOPT_URL, "https://192.168.1.194:24408/syris/device/topology");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerlist);
        curl_easy_setopt(curl, CURLOPT_SSLVERSION,CURL_SSLVERSION_TLSv1_2);// | CURL_SSLVERSION_SSLv3 | CURL_SSLVERSION_TLSv1_0 | CURL_SSLVERSION_TLSv1_2
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);//SKIP_PEER_VERIFICATION
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, false);//SKIP_HOSTNAME_VERFICATION
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
        curl_easy_setopt(curl, CURLOPT_POST, 0); // get reqest
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 0);
        curl_easy_setopt(curl, CURLOPT_READFUNCTION,NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,NULL);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 3);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 3);
        res = curl_easy_perform(curl);
        if(res !=CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
        curl_slist_free_all(headerlist);
    }
    pause();
    return 0;
}

/*
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main() {
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char error[CURL_ERROR_SIZE];
    char url[50] = "http://www.google.com.tw/"; //要下載的網址
    char outfilename[FILENAME_MAX] = "index.html"; //存檔路徑
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    if (curl) {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url); //設定網址
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        //如果有錯誤的話會將錯誤寫在這邊的error buffer
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, error);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }
    return 0;
}
*/
/*
int main()
{
	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, true);
		curl_easy_setopt(curl, CURLOPT_URL, "https://mail.qq.com");

		//example.com is redirected, so we tell libcurl to follow redirection
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		//Perform the request, res will get the return code
		res = curl_easy_perform(curl);

		//Check for errors
		if(res != CURLE_OK)
			fprintf(stderr, "curl_easy_perform() failed: %s\n",
			curl_easy_strerror(res));

		//always cleanup
		curl_easy_cleanup(curl);

	}
	return 0;

}
*/
