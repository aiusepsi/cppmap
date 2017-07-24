pipeline {
  agent none
  stages {
    stage('TestStage') {
      steps {
        parallel(
          "TestStage": {
            echo 'Hello, world!'
            
          },
          "TeststageA": {
            echo 'Boom'
            
          }
        )
      }
    }
    stage('TestStage2') {
      steps {
        parallel(
          "TestStage2": {
            node(label: 'macos') {
              echo 'Boo!'
              sh 'uname'
            }
            
            
          },
          "error": {
            node(label: 'any') {
              echo 'sad'
            }
            
            
          }
        )
      }
    }
  }
}