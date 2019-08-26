/*
 * Define your service specification in this file and run rpcgen -MN minifyjpeg.x
 */

const MAX_FILE_SIZE = 1000000000;  /* 1GB */

struct jpeg_in {  /* Data in */
    opaque data<MAX_FILE_SIZE>;
};

struct jpeg_out {  /* Data out */
    opaque data<MAX_FILE_SIZE>;
};

program JPEG_PROG {  /* RPC Service Name */
    version JPEG_VER {
        jpeg_out JPEG_MINIFY(jpeg_in) = 1;  /* Procedure */
    } = 1; 
} = 0x3654321;