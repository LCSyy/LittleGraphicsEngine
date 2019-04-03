#include "glad/glad.h"
#include "buffermanager.h"

/*!
 * \brief 用于OpenGL缓存的分配，管理和销毁。
 * 缓存对象用于管理OpenGL服务端内存分配的固定尺寸数据内存。
 *
 * GenBuffers() 用于返回n个没有被使用的缓存对象名称。
 * BindBuffer() 用于获取缓存对象的状态。
 * DeleteBuffers() 销毁内容，名称再次变为未使用状态。如果
 * 对应缓存正在使用，在销毁之前，会执行类似UnmapBuffer()的操作。
 * IsBuffer() 用于判断一个名称是否属于缓存对象。
 *
 * BindBufferRange()
 * BindBufferBase()
 * BindBuffersRange()
 * BindBuffersBase()
 */
BufferManager::BufferManager()
{

}
