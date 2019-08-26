# Image_Compression_RPC_Server_Client
Designed and implemented a pair of RPC image compression server and client. <br /> <br /> 
The RPC server will accept a jpeg image as input, downsample it to a lower resolution and return the resulting image. The RPC client invokes remote functions on the server machine as _**Remote Procedure Calls**_ to downsample the images. <br /> <br /> 
Both client and server are multi-threaded to support concurrent image compression.
