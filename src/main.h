#ifndef MAIN_H
#define MAIN_H

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include <stdint.h>
#include <cstdio>
#include "Quaternion.hpp"
#include "Sensors.hpp"
#include "feature.h"
#include "states.h"
#include "view.hpp"
#include "imagesensor.hpp"
#include "config.hpp"
using namespace cv;

typedef std::map<int,Feature> featMap;
typedef featMap::iterator featIter;
typedef std::vector<projection>::iterator matchIter;
typedef std::vector<Feature>::iterator Fiter;

void blockAssign ( cv::Mat dst, cv::Mat block, cv::Point tl );
void ARC_compare ( cv::Mat cmat, char *fn, double thresh=0 );
void hexToVec ( const char *fn, vector<double>& vec );
void loadData(vector<double>& aHist, vector<double>& altHist, vector<double>& dtHist, vector<double>& qbwHist, vector<double>& wHist);
void copyMat(Mat& src, Mat& dst);
void reshapeMat(vector<double> src, Mat& dst);
void reshapeMat3D(vector<double> src, Mat& dst);
void jacobianH(States mu, Quaternion qbw, cv::Vec3d xb0w, Quaternion qb0w, int i, Mat& Hb, Mat& Hi );
void jacobianMotionModel(States mu, Sensors sense, Mat& F_out, bool flagbias );
void measurementModel( cv::Vec3d old_pos, double alt, std::vector<projection> matches,
        Quaternion qbw, int flagMeas, bool flagbias, View& meas, View& hmu, Mat& H, States& mu );
vector<int> findIndex(const Mat& src, double val);
void initG ( cv::Mat& G, int nf, double dt, bool flagbias );
void initQ ( cv::Mat& Q, int nf, double Q0, bool flagbias );
void initR ( cv::Mat& R, int nf, double R0 );
void calcP ( cv::Mat& P, cv::Mat F, cv::Mat G, cv::Mat Q );
void calcK ( cv::Mat& K, cv::Mat H, cv::Mat P, cv::Mat R );
void updateP( cv::Mat& P, cv::Mat K, cv::Mat H );

#endif
