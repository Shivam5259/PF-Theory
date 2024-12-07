#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char mediaTitle[100];
    float mediaRating;
    int mediaDuration;
    char mediaEncoding[50];
} ContentInfo;

typedef struct{
    float deviceResolution;
    int viewingHistory;
    float dataConsumption;
} DeviceInfo;

double** allocateEngagementMatrix(int totalUsers, int totalCategories);
DeviceInfo*** allocateDeviceData(int totalUsers, int totalDevices);
ContentInfo*** allocateContentMatrix(int totalCategories, int totalItems);
void releaseEngagementMatrix(double **matrix, int totalUsers);
void releaseDeviceData(DeviceInfo ***matrix, int totalUsers, int totalDevices);
void releaseContentMatrix(ContentInfo ***matrix, int totalCategories, int totalItems);

int main(){
    int users, categories, devices, items;

    printf("Enter the number of users: ");
    scanf("%d", &users);
    printf("Enter the number of content categories: ");
    scanf("%d", &categories);
    printf("Enter the number of devices per user: ");
    scanf("%d", &devices);
    printf("Enter the number of content items per category: ");
    scanf("%d", &items);

    double **engagementMatrix = allocateEngagementMatrix(users, categories);
    DeviceInfo ***deviceMatrix = allocateDeviceData(users, devices);
    ContentInfo ***contentMatrix = allocateContentMatrix(categories, items);

    for (int i = 0; i < users; i++){
        for (int j = 0; j < categories; j++){
            printf("Enter engagement score for User %d in Category %d: ", i + 1, j + 1);
            scanf("%lf", &engagementMatrix[i][j]);
        }
    }

    for (int i = 0; i < users; i++){
        for (int j = 0; j < devices; j++){
            printf("Enter resolution for User %d on Device %d: ", i + 1, j + 1);
            scanf("%f", &deviceMatrix[i][j]->deviceResolution);
            printf("Enter viewing history for User %d on Device %d: ", i + 1, j + 1);
            scanf("%d", &deviceMatrix[i][j]->viewingHistory);
            printf("Enter data usage for User %d on Device %d: ", i + 1, j + 1);
            scanf("%f", &deviceMatrix[i][j]->dataConsumption);
        }
    }

    for (int i = 0; i < categories; i++){
        for (int j = 0; j < items; j++){
            printf("Enter title for Content %d in Category %d: ", j + 1, i + 1);
            getchar();
            fgets(contentMatrix[i][j]->mediaTitle, sizeof(contentMatrix[i][j]->mediaTitle), stdin);
            contentMatrix[i][j]->mediaTitle[strcspn(contentMatrix[i][j]->mediaTitle, "\n")] = '\0';
            printf("Enter rating for Content %d in Category %d: ", j + 1, i + 1);
            scanf("%f", &contentMatrix[i][j]->mediaRating);
            printf("Enter duration for Content %d in Category %d: ", j + 1, i + 1);
            scanf("%d", &contentMatrix[i][j]->mediaDuration);
            printf("Enter encoding for Content %d in Category %d: ", j + 1, i + 1);
            getchar();
            fgets(contentMatrix[i][j]->mediaEncoding, sizeof(contentMatrix[i][j]->mediaEncoding), stdin);
            contentMatrix[i][j]->mediaEncoding[strcspn(contentMatrix[i][j]->mediaEncoding, "\n")] = '\0';
        }
    }

    printf("\nEngagement Scores:\n");
    for (int i = 0; i < users; i++){
        for (int j = 0; j < categories; j++){
            printf("User %d, Category %d: %.2f\n", i + 1, j + 1, engagementMatrix[i][j]);
        }
    }

    printf("\nDevice Preferences:\n");
    for (int i = 0; i < users; i++){
        for (int j = 0; j < devices; j++){
            printf("User %d, Device %d - Resolution: %.2f, History: %d mins, Data: %.2f GB\n",
                   i + 1, j + 1, deviceMatrix[i][j]->deviceResolution, deviceMatrix[i][j]->viewingHistory, deviceMatrix[i][j]->dataConsumption);
        }
    }

    printf("\nContent Information:\n");
    for (int i = 0; i < categories; i++){
        for (int j = 0; j < items; j++){
            printf("Category %d, Content %d - Title: %s, Rating: %.2f, Duration: %d mins, Encoding: %s\n",
                   i + 1, j + 1, contentMatrix[i][j]->mediaTitle, contentMatrix[i][j]->mediaRating, contentMatrix[i][j]->mediaDuration, contentMatrix[i][j]->mediaEncoding);
        }
    }

    releaseEngagementMatrix(engagementMatrix, users);
    releaseDeviceData(deviceMatrix, users, devices);
    releaseContentMatrix(contentMatrix, categories, items);
}

double** allocateEngagementMatrix(int totalUsers, int totalCategories){
    double **engagement = malloc(totalUsers * sizeof(double*));
    for (int i = 0; i < totalUsers; i++) {
        engagement[i] = malloc(totalCategories * sizeof(double));
    }
    return engagement;
}

DeviceInfo*** allocateDeviceData(int totalUsers, int totalDevices){
    DeviceInfo ***deviceDetails = malloc(totalUsers * sizeof(DeviceInfo**));
    for (int i = 0; i < totalUsers; i++){
        deviceDetails[i] = malloc(totalDevices * sizeof(DeviceInfo*));
        for (int j = 0; j < totalDevices; j++){
            deviceDetails[i][j] = malloc(sizeof(DeviceInfo));
        }
    }
    return deviceDetails;
}

ContentInfo*** allocateContentMatrix(int totalCategories, int totalItems){
    ContentInfo ***contentDetails = malloc(totalCategories * sizeof(ContentInfo**));
    for (int i = 0; i < totalCategories; i++){
        contentDetails[i] = malloc(totalItems * sizeof(ContentInfo*));
        for (int j = 0; j < totalItems; j++){
            contentDetails[i][j] = malloc(sizeof(ContentInfo));
        }
    }
    return contentDetails;
}

void releaseEngagementMatrix(double **matrix, int totalUsers) {
    for (int i = 0; i < totalUsers; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void releaseDeviceData(DeviceInfo ***matrix, int totalUsers, int totalDevices) {
    for (int i = 0; i < totalUsers; i++) {
        for (int j = 0; j < totalDevices; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

void releaseContentMatrix(ContentInfo ***matrix, int totalCategories, int totalItems) {
    for (int i = 0; i < totalCategories; i++) {
        for (int j = 0; j < totalItems; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

