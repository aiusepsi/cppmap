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
        node(label: 'macOS') {
          echo 'Boo!'
          sh 'uname'
        }
        
      }
    }
  }
}