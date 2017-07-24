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
            warnings()
            
          },
          "TeststageA": {
            echo 'Boom'
            
          }
        )
      }
    }
    stage('TestStage2') {
      steps {
        node(label: 'Blah') {
          echo 'Boo!'
        }
        
      }
    }
  }
}