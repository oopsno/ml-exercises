#/bin/bash

BASE_URL="http://openclassroom.stanford.edu/MainFolder/courses/MachineLearning/exercises"
DATASER_DIR=$(dirname $0)
BASE_DIR="${DATASER_DIR}/archives"

function data_filename {
    echo "ex${1}Data.zip"
}

function url {
    echo "${BASE_URL}/ex${1}materials/$(data_filename $1)"
}

function local_path {
    echo "${BASE_DIR}/$(data_filename $1)"
}

function unzip_path {
    RETVAL="${DATASER_DIR}/exercise_${1}"
    mkdir -p ${RETVAL}
    echo ${RETVAL}
}

function process_normal_dataset {
    echo "Downloading dataset ${1}"
    curl $(url $1) > $(local_path $1)
    echo "Unzipping..."
    unzip $(local_path $1) -d $(unzip_path $1)
}

function process_ex6_dataset {
    BASE_URL_EX6="${BASE_URL}/ex6materials"
    PREPARED="ex6DataPrepared.zip"
    EMAILS="ex6DataEmails.zip"
    echo "Downloading dataset 6"
    curl "${BASE_URL_EX6}/${PREPARED}" > "${BASE_DIR}/${PREPARED}"
    curl "${BASE_URL_EX6}/${EMAILS}" > "${BASE_DIR}/${EMAILS}"
    echo "Unzipping..."
    unzip "${BASE_DIR}/${PREPARED}" -d $(unzip_path 6)
    unzip "${BASE_DIR}/${EMAILS}"   -d $(unzip_path 6)
}

function process_dataset {
    if [ $1 != 6 ] ; then
        process_normal_dataset $1
    else
        process_ex6_dataset
    fi
}

function download_dataset {
    mkdir -p $BASE_DIR
    for id in $(seq 2 9) ; do
        process_dataset $id
    done
}

download_dataset

