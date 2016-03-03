#/bin/bash

DATASET_DIR=$(dirname $0);

function clear_dataset {
    rm -rf ${DATASET_DIR}/archives
    for i in $(seq 2 9) ; do
        rm -rf ${DATASET_DIR}/exercise_${i}
    done
}

clear_dataset
