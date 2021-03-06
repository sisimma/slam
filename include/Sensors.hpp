#ifndef  Sensors_INC
#define  Sensors_INC
#define MAXLINE 1024            /*  */
#include <cv.h>
#include "Quaternion.hpp"
/*
 * =====================================================================================
 *        Class:  Sensors
 *  Description:  Store sensor data.
 * =====================================================================================
 */
class Sensors
{
    public:
        /* ====================  LIFECYCLE     ======================================= */

        /* ====================  ACCESSORS     ======================================= */
        double get_altitude();

        double get_dt();

        cv::Vec3d get_acceleration ( );  
        cv::Vec3d get_angular_velocity ( );
        cv::Vec4d get_quaternion ( );


        /* ====================  MUTATORS      ======================================= */
        void update();
        void set_acceleration( const char *fn, bool isHex, bool isRealTime=false ) { 
            accelerationIsHex = isHex;
            accelerationIsRealTime = isRealTime;
            if( !accelerationIsRealTime )
            {
                acceleration_fp=open_source(fn); 
            }
            else
            {
                acceleration_fn = fn;
            }
        }

        void set_altitude ( const char *fn, bool isHex, bool isRealTime=false ) {
            altitudeIsHex = isHex;
            altitudeIsRealTime = isRealTime;
            if( !altitudeIsRealTime )
            {
                altitude_fp = open_source(fn);
            }
            else
            {
                altitude_fn = fn;
            }
        }		

        void set_quaternion( const char *fn, bool isHex, bool isRealTime ) { 
            quaternionIsHex = isHex;
            quaternionIsRealTime = isRealTime;
            if( !quaternionIsRealTime )
            {
                quaternion_fp=open_source(fn); 
            }
            else
            {
                quaternion_fn = fn;
            }
        }

        void set_dt ( const char *fn, bool isHex, bool isRealTime=false ) {
            dtIsHex = isHex;
            dtIsRealTime = isRealTime;
            if( !dtIsRealTime )
                dt_fp = open_source(fn);
            else
                dt_fn = fn;
        }		

        void set_angular_velocity( const char *fn, bool isHex, bool isRealTime=false ) { 
            angular_velocityIsHex = isHex;
            angular_velocityIsRealTime = isRealTime;
            if( !angular_velocityIsRealTime )
                angular_velocity_fp=open_source(fn);
            else
                angular_velocity_fn = fn;
        }

        /* ====================  OPERATORS     ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */
        double altitude;
        cv::Vec3d acceleration, angular_velocity;
        Quaternion quaternion;
        double dt;

    protected:
        /* ====================  METHODS       ======================================= */

        /* ====================  DATA MEMBERS  ======================================= */

    private:
        /* ====================  METHODS       ======================================= */
        cv::Vec3d Mat2Vec3d( cv::Mat src, int timestep );
        cv::Vec4d Mat2Vec4d( cv::Mat src, int timestep );
        FILE* open_source ( const char *fn );
        void get_val ( FILE* fp, const char *str, const char *fmt, ... );

        /* ====================  DATA MEMBERS  ======================================= */
        bool accelerationIsHex, altitudeIsHex, angular_velocityIsHex, dtIsHex,
             quaternionIsHex;
        bool angular_velocityIsRealTime, dtIsRealTime, altitudeIsRealTime,
             accelerationIsRealTime, quaternionIsRealTime;

        /* Sources */
        std::string angular_velocity_fn, dt_fn, altitude_fn, acceleration_fn,
            quaternion_fn;
        FILE *angular_velocity_fp, *altitude_fp, *dt_fp, *acceleration_fp,
             *quaternion_fp;

}; /* -----  end of class Sensors  ----- */

#endif   /* ----- #ifndef Sensors_INC  ----- */
