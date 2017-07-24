pipeline {
  agent {
    docker {
      image 'ubuntu'
    }
    
  }
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
        node(label: 'macos') {
          echo 'Boo!'
          sh 'uname'
        }
        
      }
    }
  }
}