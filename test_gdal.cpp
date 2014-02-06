#include <gdal_priv.h>
#include <cpl_conv.h>

int main(int argc, char *argv[])
{
    GDALDataset *poDataset;
    double        adfGeoTransform[6];

    GDALAllRegister();
    
    
    poDataset = (GDALDataset*) GDALOpen( "test_alu_3_fomed_nanfilled_map.cub", GA_ReadOnly );


    printf( "Driver: %s/%s\n",
            poDataset->GetDriver()->GetDescription(), 
            poDataset->GetDriver()->GetMetadataItem( GDAL_DMD_LONGNAME ) );

    printf( "Size is %dx%dx%d\n", 
            poDataset->GetRasterXSize(), poDataset->GetRasterYSize(),
            poDataset->GetRasterCount() );

    if( poDataset->GetProjectionRef()  != NULL )
        printf( "Projection is `%s'\n", poDataset->GetProjectionRef() );

    if( poDataset->GetGeoTransform( adfGeoTransform ) == CE_None )
    {
        printf( "Origin = (%.6f,%.6f)\n",
                adfGeoTransform[0], adfGeoTransform[3] );

        printf( "Pixel Size = (%.6f,%.6f)\n",
                adfGeoTransform[1], adfGeoTransform[5] );
    }
    
    
}
