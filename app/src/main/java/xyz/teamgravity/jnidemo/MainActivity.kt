package xyz.teamgravity.jnidemo

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Scaffold
import androidx.compose.ui.Modifier
import xyz.teamgravity.jnidemo.ui.theme.JNIDemoTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContent {
            JNIDemoTheme {
                Scaffold(
                    modifier = Modifier.fillMaxSize()
                ) { padding ->

                }
            }
        }
    }
}