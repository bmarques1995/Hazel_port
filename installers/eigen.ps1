param (
    [string]$buildMode = "",
    [string]$installPrefix = ""
)

Write-Output "$installPrefix"

if (($buildMode -eq "Debug" -or $buildMode -eq "Release") -and ($installPrefix -ne ""))
{
    cmake -S ./modules/eigen3 -B ./dependencies/eigen3 -DCMAKE_BUILD_TYPE="$buildMode" -DCMAKE_INSTALL_PREFIX="$installPrefix"
    cmake --build ./dependencies/eigen3 --config "$buildMode" --target install
} 
else 
{
    Write-Output "Invalid build args"
}