@echo off

cd /D "%~dp0"

IF NOT exist "P:\Steve\" (
	echo Creating folder P:\Steve\
	mkdir "P:\Steve"
)

IF exist "P:\Steve\MVCUIM\" (
	echo Removing existing link P:\Steve\MVCUIM
	rmdir "P:\Steve\MVCUIM\"
)

echo Creating link P:\Steve\MVCUIM
mklink /J "P:\Steve\MVCUIM\" "D:\Github\MVCUIManager\MVCUIManager\Steve\MVCUIM\"

echo Done